/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:14:46 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/22 13:12:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"

void print_winner(t_vm *vm)
{
	uint8_t   i;
	int64_t   winner_id;
	t_player *players;

	winner_id = vm->last_player_report_as_live;
	players = vm->players;
	i = 0;
	DEBUG_CYCLE &&ft_printf("\e[2Kcycle: %zu\n", vm->cycle_count);
	while (i < vm->players_count)
	{
		if (players[i].id == winner_id)
		{
			ft_printf("Le Champion %zd (%s) a écrasé ces ennemies\n",
				players[i].id, players[i].header.prog_name);
			return;
		}
		i++;
	}
	ft_printf("aucun champion ne mérite la victoire\n");
}
