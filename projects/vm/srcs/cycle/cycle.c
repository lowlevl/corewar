/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 13:49:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "libpf.h"

void setup_next_cycle(t_vm *vm)
{
	vm->nb_live_for_cycle = 0;
	vm->next_check = vm->cycle_count + vm->cycle_to_die;
}

size_t count_alive_processes(t_process *process, size_t process_count)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (i < process_count)
	{
		if (process[i].have_live != 0)
			count++;
		i++;
	}
	return count;
}

void reset_process_have_live(t_process *processes, size_t process_count)
{
	size_t i;

	i = 0;
	while (i < process_count)
	{
		processes[i].have_live = 0;
		i++;
	}
}

void filter_process_have_live(t_vm *vm)
{
	size_t	 i;
	size_t	 p;
	size_t	 nb;
	t_process *process_filtered;
	t_process *processes;

	processes = vm->processes;
	nb = count_alive_processes(processes, vm->processes_count);
	if (nb == vm->processes_count)
		return reset_process_have_live(processes, nb);
	process_filtered = (t_process *)malloc(nb * sizeof(t_process));
	i = 0;
	p = 0;
	while (i < nb)
	{
		if (processes[i].have_live)
		{
			processes[i].have_live = 0;
			process_filtered[p++] = processes[i];
		}
		i++;
	}
	free(vm->processes);
	vm->processes_count = nb;
	vm->processes = process_filtered;
}

void check_cycle(t_vm *vm)
{
	if (vm->next_check == vm->cycle_count)
	{
		if (vm->nb_live_for_cycle >= NBR_LIVE || vm->nb_check >= MAX_CHECKS)
		{
			vm->nb_check = 1;
			vm->cycle_to_die -= CYCLE_DELTA;
		}
		else
			vm->nb_check++;
		filter_process_have_live(vm);
		setup_next_cycle(vm);
	}
}

void exec_cycle(t_vm *vm)
{
	uint64_t   i;
	t_process *process;

	i = 0;
	while (i < vm->processes_count)
	{
		process = vm->processes + i;
		exec_process(vm, process);
		i++;
	}
	check_cycle(vm);
	vm->cycle_count++;
}

void cycle_until_death(t_vm *vm)
{
	while (vm->processes_count > 0 && vm->cycle_to_die > 0)
	{
		exec_cycle(vm);
	}
}

void cycle_until_dump(t_vm *vm)
{
	while (vm->cycle_count < vm->dump && vm->processes_count > 0 &&
		   vm->cycle_to_die > 0)
	{
		exec_cycle(vm);
	}
}

void make_cycle(t_vm *vm)
{
	if (vm->dump == -1)
		cycle_until_death(vm);
	else
		cycle_until_dump(vm);
}
