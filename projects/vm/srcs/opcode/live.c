/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:01:28 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/22 11:09:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static void report_as_live(t_vm *vm, t_player *player)
{
	vm->last_player_report_as_live = player->id;
	vm->nb_live_for_cycle++;
	player->total_live_count++;
	ft_printf("un processus a dit que le joueur %d (%s) est en vie\n",
		player->id, player->header.prog_name);
}

void exec_live(t_vm *vm, t_process *process, const t_op *op)
{
	int32_t   player_id;
	t_player *player;

	(void)op;
	player_id = read_arg(process, vm->memory, T_DIR_4);
	player = find_player(vm->players, vm->players_count, player_id);
	process->have_live = 1;
	DEBUG_R_FC &&ft_dprintf(2, "live %%%d\n", player_id);
	if (player)
	{
		report_as_live(vm, player);
	}
	else
	{
		ft_printf("un processus souhaite que le joueur avec l'id %d soit en "
				  "vie,\n mais je ne connais de telle joueur\n",
			player_id);
	}
}
