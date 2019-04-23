/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:14:46 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/23 10:59:19 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "stdlib.h"

#define NO_WIN "<winner noWinner=\"true\"><id>-1</id><name>NONE</name></winner>"
#define FORMAT_NO_WINNER HEADER_SOCKET NO_WIN
#define TEMPLATE_BASE "WINNER - nº%d / %s :: "
#define TEMPLATE_COUNT sizeof(g_templates) / sizeof(char *)

static char *g_templates[] = {
	TEMPLATE_BASE "Veni vidi vici.\"\n",
	TEMPLATE_BASE "L’invincibilité se trouve dans la défense, la "
	"possibilité de victoire dans l’attaque. Celui qui se défend montre "
	"que sa force est inadéquate, celui qui attaque qu’elle est"
	"abondante.\"\n",
	TEMPLATE_BASE "Veni vidi easy.\"\n",
	TEMPLATE_BASE "Fatality.\"\n",
	TEMPLATE_BASE "Ha, trop facile !\"\n",
	TEMPLATE_BASE "Easy peazy lemon squezy\n",
};

void	print_random_citation(int player_id, char *player_name) {
	char *template;

	template = g_templates[rand() % TEMPLATE_COUNT];
	ft_printf(template, player_id, player_name);
}

void	print_winner(t_vm *vm)
{
	uint8_t		i;
	int64_t		winner_id;
	t_player	*players;
	int32_t		len;
	char		*s;

	winner_id = vm->last_player_report_as_live;
	players = vm->players;
	i = -1;
	DEBUG_CYCLE && ft_dprintf(2, CYCLE_PREFIX "cycle: %zu\n", vm->cycle_count);
	while (++i < vm->players_count)
	{
		if (players[i].id == winner_id)
		{
			if (vm->random_talk)
				print_random_citation(winner_id, players[i].header.prog_name);
			else
			{
				ft_printf("WINNER - Le Champion %zd (%s) a écrasé ses ennemis.",
						players[i].id, players[i].header.prog_name);
				if (vm->players_count <= 1)
					ft_printf(" (en même temps, il était seul)\n");
				else
					ft_printf("\n");
			}
			send_winner(players + i, &vm->socket);
			return ;
		}
	}
	len = ft_asprintf(&s, FORMAT_NO_WINNER);
	ft_memcpy(s, &len, sizeof(len));
	send_message_to_all(&vm->socket, s, len);
	free(s);
	ft_printf("Aucun champion n'a gagné, du coup on pourrait dire que tout"
			" le monde à perdu ? ...\n");
}
