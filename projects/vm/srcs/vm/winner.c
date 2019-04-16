/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:14:46 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/09 13:12:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define FORMAT_NO_WINNER                                                       \
	HEADER_SOCKET                                                              \
		"<winner noWinner=\"true\"><id>-1</id><name>NONE</name></winner>"

void print_winner(t_vm *vm)
{
	uint8_t   i;
	int64_t   winner_id;
	t_player *players;
	int32_t   len;
	char *	s;

	winner_id = vm->last_player_report_as_live;
	players = vm->players;
	i = 0;
	DEBUG_CYCLE &&ft_dprintf(2, CYCLE_PREFIX "cycle: %zu\n", vm->cycle_count);
	while (i < vm->players_count)
	{
		if (players[i].id == winner_id)
		{
			ft_printf("Le Champion %zd (%s) a écrasé ces ennemies\n",
				players[i].id, players[i].header.prog_name);
			if (vm->players_count <= 1)
				ft_printf("(en même temps, il était seul)\n");
			send_winner(players + i, &vm->socket);
			return;
		}
		i++;
	}
	len = ft_asprintf(&s, FORMAT_NO_WINNER);
	ft_memcpy(s, &len, sizeof(len));
	send_message_to_all(&vm->socket, s, len);
	free(s);
	ft_printf("aucun champion ne mérite la victoire\n");
}
