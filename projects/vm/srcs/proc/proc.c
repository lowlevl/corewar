/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 20:23:07 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_vm *vm)
{
	int i;

	i = 0;
	while  (i < vm->players_count)
	{
		init_process(vm, i);
		i++;
	}
}

void	init_process(t_vm *vm, int player_idx)
{
		vm->processes = (t_process*)malloc(sizeof(t_process));
		if_errno_printerr_exit(ERR_PROC_MALL);
		vm->processes_count = 1;
		vm->processes->carry = 0;
		vm->processes->waiting = -1;
		vm->processes->cursor_pos = 0;
		vm->processes->cursor_start =
			(uint32_t)(get_start_in_memory(vm, player_idx) - (void *)vm->memory);
		// print_proc(player->processes); // Debug
}

void	add_processes(t_vm *vm, uint16_t pc)
{
	size_t n;
	t_process *proc;

	n = vm->processes_count;
	vm->processes
		= (t_process*)realloc(vm->processes, sizeof(t_process) * n);
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	vm->processes_count++;
	proc = vm->processes + n;
	proc->cursor_pos = 0;
	proc->carry = 0;
	proc->cursor_start = pc;
	proc->waiting = -1;
}

void	exec_cycle(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->processes_count)
	{
		i++;
	}
}

