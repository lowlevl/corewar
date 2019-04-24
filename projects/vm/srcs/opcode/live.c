/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:01:28 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/24 13:53:05 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "socket.h"
#include "stdlib.h"

#define TEMPLATE_COUNT sizeof(g_templates) / sizeof(char *)
#define TEMPLATE_BASE "LIVE - Champ nº%d (%s) :: \""

static char *g_templates[] = {
	"LIVE - Champ nº%d (%s)\n",
	TEMPLATE_BASE "Je suis en vie!\"\n",
	TEMPLATE_BASE "Toi, tu refuses de me tuer par principe. Et moi, je refuse"
	"de te tuer parce que tu es tellement amusant.\"\n",
	TEMPLATE_BASE "La vie est un mystère qu'il faut vivre, et non un problème"
	"à résoudre.\"\n",
	TEMPLATE_BASE "La vie, c'est comme une bicyclette, il faut avancer pour "
	"ne pas perdrel'équilibre.\"\n",
	TEMPLATE_BASE "Que serait la vie, sans notre Maman.\"\n",
	TEMPLATE_BASE "Quand on ne sait pas ce qu'est la vie, comment "
	"pourrait-on savoir ce qu'est la mort ?\"\n",
	TEMPLATE_BASE "Qui suis-je? Où vais-je? Qu'est-ce qu'on mange à midi?\"\n",
	TEMPLATE_BASE "La bible ne fait pas le moine\"\n",
	TEMPLATE_BASE "Un clavier azerty en vaut deux\"\n",
	TEMPLATE_BASE "C'est en forgeant qu'on devient forgeron, mais ce n'est "
	"pas en se mouchant que l'on devient moucheron, ni en sciant que "
	"Léonard devint scie.\"\n",
	TEMPLATE_BASE "Jésus crie, la caravane passe.\"\n",
	TEMPLATE_BASE "Canicule en été, mamie va y passer\"\n",
};

static void	print_live(int random, int player_id, char *player_name)
{
	const char *template;

	if (random)
		template = g_templates[(rand() % (TEMPLATE_COUNT - 1)) + 1];
	else
		template = g_templates[0];
	ft_printf(template, player_id, player_name);
}

static void	report_as_live(t_vm *vm, t_player *player)
{
	vm->last_player_report_as_live = player->id;
	vm->nb_live_for_cycle++;
	player->total_live_count++;
	send_live(&vm->socket, player->id);
	print_live(vm->random_talk, player->id, player->header.prog_name);
}

void		exec_live(t_vm *vm, t_process *process, const t_op *op)
{
	int32_t		player_id;
	t_player	*player;

	(void)op;
	player_id = read_arg(process, vm->memory, T_DIR_4);
	player = find_player(vm->players, vm->players_count, player_id);
	process->have_live = 1;
	DEBUG_R_FC && ft_dprintf(2, FUNC_PREFIX "live %%%d\n", player_id);
	if (player)
		report_as_live(vm, player);
	else
		ft_printf("LIVE - Un champion inconnu (%d) a été signalé en vie.\n",
				player_id);
}
