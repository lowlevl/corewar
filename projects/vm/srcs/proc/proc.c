/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 11:55:26 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_vm *vm)
{
	uint8_t i;
	t_player *player;


	i = 0;
	while  (i < vm->players_count)
	{
		player = vm->players + i;
		player->processes = (t_process*)malloc(sizeof(t_process));
		if_errno_printerr_exit(ERR_PROC_MALL);
		player->processes_count = 1;
		player->processes[1]
			= (t_process){
				.player_id = player->id,
				.cursor_pos = 0,
				.carry = 0,
				.waiting = -1,
				.cursor_start = get_start_in_memory(vm, i),
			};
		i++;
	}
}

void add_processes(t_player *player, uint16_t pc)
{
	size_t n;

	n = player->processes_count;
	player->processes
		= (t_process*)realloc(player->processes, sizeof(t_process) * n);
	if_errno_printerr_exit(ERR_NEW_PROC_MALL);
	player->processes_count++;
	player->processes[n]
		= (t_process){
			.player_id = player->id,
			.cursor_pos = 0,
			.carry = 0,
			.cursor_start = pc,
			.waiting = -1,
		};
}
