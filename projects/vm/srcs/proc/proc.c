/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/26 16:33:31 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_vm *vm)
{
	int		i;
	size_t  start;
	int32_t player_id;

	i = 0;
	vm->processes = NULL;
	if_errno_printerr_exit(ERR_PROC_MALL);
	vm->processes_count = vm->players_count;
	while (i < vm->players_count)
	{
		start = get_start_idx_in_memory(vm->players_count, i);
		player_id = vm->players[vm->sorted_players_idx[i]].id;
		init_process(&vm->processes, start, player_id);
		i++;
	}
}

void init_process(t_process **head, uint16_t cursor_start, int32_t player_id)
{
	t_process *proc;

	proc = (t_process *)malloc(sizeof(t_process));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	ft_memset(proc, 0, sizeof(t_process));
	proc->exec_cycle = -1;
	proc->cursor_start = cursor_start;
	proc->player_id = player_id;
	proc->regs[0] = player_id;
	proc->next = (*head);
	*head = proc;
	print_proc(proc);
}

void delete_process(t_process **head)
{
	t_process *node;
	t_process *tmp;

	if (!head || !*head)
		return;
	node = *head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*head = NULL;
}

void copy_process(t_vm *vm, t_process *process, size_t pos)
{
	t_process *dup;

	dup = (t_process *)malloc(sizeof(t_process));
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	ft_memcpy(dup, process, sizeof(t_process));
	dup->cursor_pos = pos;
	vm->processes_count++;
	dup->next = vm->processes;
	vm->processes = dup;
}
