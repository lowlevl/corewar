/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:53:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 14:36:12 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

# define FORMAT_PLAYER "<player id=\"%d\" name=\"%s\" />"

static void do_stuff(t_player *player, t_socket *socket)
{
	char * s;
	size_t len;

	len = ft_asprintf(&s, FORMAT_PLAYER, player->id, player->header.prog_name);
	if (s && len > 0)
	{
		DEBUG_SOCKET_SEND &&ft_dprintf(2, SOCKET_PLAYER, s);
		send_message_to_all(socket, s, len);
		free(s);
	}
}

int send_player(t_vm *vm)
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
