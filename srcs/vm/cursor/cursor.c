/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 16:58:02 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cursor.h>

void init_cursor(t_player *players, uint8_t count)
{
	uint8_t i;
	t_player *player;

	i = 0;
	while  (i < count)
	{
		player = players + i;
		player->processes = malloc(sizeof(t_process));
		if_errno_printerr_exit(ERR_PROC_MALL);
		player->processes_count = 1;
		player->processes[1]
			= (t_process){ player_id: player->id, pc: 0, carry: 0 };
		i++;
	}
}
