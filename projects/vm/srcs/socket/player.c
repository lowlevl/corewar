/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:53:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/11 09:37:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FORMAT_PLAYER                                                          \
	HEADER_SOCKET "<player> <id>%d</id> <name>%s</name> </player>"
#define FORMAT_WINNER                                                          \
	HEADER_SOCKET                                                              \
		"<winner noWinner=\"false\"> <id>%d</id> <name>%s</name> </winner>"

static void do_stuff(t_player *player, t_socket *socket)
{
	char *  s;
	int32_t len;

	len = ft_asprintf(&s, FORMAT_PLAYER, player->id, player->header.prog_name);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
}

int send_players(t_vm *vm)
{
	uint8_t i;

	if (vm->socket.enable != ENABLE_SOCKET)
		return 0;
	i = 0;
	while (i < vm->players_count)
	{
		do_stuff(vm->players + i, &vm->socket);
		i++;
	}
	return 0;
}

int send_winner(t_player *player, t_socket *socket)
{
	char *  s;
	int32_t len;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	len = ft_asprintf(&s, FORMAT_WINNER, player->id, player->header.prog_name);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
	return len;
}
