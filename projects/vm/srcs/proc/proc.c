/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 14:20:58 by glodi            ###   ########.fr       */
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
		t_player *player;

		player = vm->players + player_idx;
		player->processes = (t_process*)malloc(sizeof(t_process));
		if_errno_printerr_exit(ERR_PROC_MALL);
		player->processes_count = 1;
		player->processes->carry = 0;
		player->processes->player_id = player->id;
		player->processes->waiting = -1;
		player->processes->cursor_pos = 0;
		player->processes->cursor_start =
			(uint32_t)(get_start_in_memory(vm, player_idx) - (void *)vm->memory);
		print_proc(player->processes); // Debug
}

void add_processes(t_player *player, uint16_t pc)
{
	size_t n;
	t_process *proc;

	n = player->processes_count;
	player->processes
		= (t_process*)realloc(player->processes, sizeof(t_process) * n);
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	player->processes_count++;
	proc = player->processes + n;
	proc->player_id = player->id;
	proc->cursor_pos = 0;
	proc->carry = 0;
	proc->cursor_start = pc;
	proc->waiting = -1;
}
