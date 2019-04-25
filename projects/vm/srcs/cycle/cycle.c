/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/24 13:51:30 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "libpf.h"
#include "socket.h"

void	check_cycle(t_vm *vm)
{
	if (vm->next_check <= vm->cycle_count)
	{
		DEBUG_CHECK && ft_dprintf(2,
			CHECK_PREFIX "cycle(%d) live(%d) check(%d)\n", vm->cycle_count,
			vm->nb_live_for_cycle, vm->nb_check);
		vm->nb_check++;
		if (vm->nb_live_for_cycle >= NBR_LIVE || vm->nb_check >= MAX_CHECKS)
		{
			vm->nb_check = 0;
			vm->cycle_to_die -= CYCLE_DELTA;
			DEBUG_CHECK && ft_dprintf(
				2, CHECK_PREFIX "dec todie(%d)\n", vm->cycle_to_die);
		}
		filter_process_have_live(vm);
		vm->nb_live_for_cycle = 0;
		vm->next_check = vm->cycle_count + vm->cycle_to_die;
		DEBUG_CHECK && ft_dprintf(2, CHECK_PREFIX "next(%d) todie(%d)\n",
				vm->next_check, vm->cycle_to_die);
	}
}

void	exec_cycle(t_vm *vm)
{
	t_process	*process;
	size_t		count;

	count = 0;
	process = vm->processes;
	vm->jump_to = vm->next_check;
	DEBUG_STEP && ft_dprintf(2, D_STEP, vm->cycle_count);
	send_procs(vm);
	send_cycle(&vm->socket, vm);
	while (process)
	{
		exec_process(vm, process);
		process = process->next;
		count++;
	}
	DEBUG_PROC && ft_dprintf(2, PROC_PRE "total(%d)\n", count);
	DEBUG_SET_JUMP && ft_dprintf(2, JUMP, vm->jump_to);
	if (vm->disable_jump == 0 && vm->cycle_count < vm->jump_to)
		vm->cycle_count = vm->jump_to;
	else
		vm->cycle_count++;
	check_cycle(vm);
}

void	cycle_until_death(t_vm *vm)
{
	while (vm->processes_count > 0)
		exec_cycle(vm);
}

void	cycle_until_dump(t_vm *vm)
{
	while (vm->cycle_count < vm->dump && vm->processes_count > 0)
		exec_cycle(vm);
}

void	make_cycle(t_vm *vm)
{
	if (vm->dump == -1)
		cycle_until_death(vm);
	else
		cycle_until_dump(vm);
}
