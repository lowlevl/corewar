/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 16:32:16 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proc.h>

void init_processes(t_player *players, uint8_t count)
{
	uint8_t i;
	t_player *player;

	i = 0;
	while  (i < count)
	{
		player = players + i;
		player->processes = (t_process*)malloc(sizeof(t_process));
		if_errno_printerr_exit(ERR_PROC_MALL);
		player->processes_count = 1;
		player->processes[1] = (t_process){ .player_id = player->id,
			.cursor_pos = 0, .carry = 0 };
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
	player->processes[n] = (t_process){ .player_id = player->id,
		.cursor_pos = pc, .carry = 0 };
}
