/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 09:49:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_vm *vm)
{
	int		i;
	size_t  start;
	int32_t player_id;

	i = 0;
	vm->processes =
		(t_process *)ft_calloc(vm->players_count, sizeof(t_process));
	if_errno_printerr_exit(ERR_PROC_MALL);
	vm->processes_count = vm->players_count;
	while (i < vm->players_count)
	{
		start = get_start_idx_in_memory(vm->players_count, i);
		player_id = vm->players[vm->sorted_players_idx[i]].id;
		init_process(vm, start, i, player_id);
		i++;
	}
}

void init_process(t_vm *vm, uint16_t cursor_start, int index, int32_t player_id)
{
	vm->processes[index].carry = 0;
	vm->processes[index].exec_cycle = 0;
	vm->processes[index].cursor_pos = 0;
	vm->processes[index].cursor_start = cursor_start;
	vm->processes[index].player_id = player_id;
	vm->processes[index].regs[0] = player_id;
}

void add_process(t_vm *vm, uint16_t pc, int player_id)
{
	size_t	 n;
	t_process *proc;

	n = vm->processes_count;
	vm->processes =
		(t_process *)realloc(vm->processes, sizeof(t_process) * (n + 1));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	vm->processes_count++;
	proc = vm->processes + n;
	ft_printf("%p\n", proc);
	proc->player_id = player_id;
	proc->cursor_pos = 0;
	proc->carry = 0;
	proc->exec_cycle = 0;
	proc->cursor_start = pc;
}
