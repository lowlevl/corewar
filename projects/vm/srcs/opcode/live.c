/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:01:28 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 09:32:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static t_player *get_player(t_vm *vm, int32_t player_id)
{
	t_player *players;
	uint8_t   i;

	players = vm->players;
	i = 0;
	while (i < vm->players_count)
	{
		if (players[i].id == player_id)
			return players + i;
	}
	return NULL;
}

static void report_as_live(t_vm *vm, t_player *player)
{
	vm->last_player_report_as_live = player->id;
	player->total_live_count++;
	player->cycle_live_count++;
	ft_printf("un processus a dit que le joueur %d(%s) est en vie\n",
		player->id, player->header.prog_name);
}

void exec_live(t_vm *vm, t_process *process, const t_op *op)
{
	int32_t   player_id;
	t_player *player;

	(void)op;
	player_id = read_arg(process, vm->memory, T_DIR);
	player = get_player(vm, player_id);
	if (player)
	{
		report_as_live(vm, player);
	}
}
