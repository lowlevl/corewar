/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:53:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 11:56:37 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FUCK_1 "<player> <id>%d</id> <size>%d</size> <name>%s</name> </player>"
#define FORMAT_PLAYER HEADER_SOCKET FUCK_1
#define FUU2 "<winner noWinner=\"false\"> <id>%d</id> <size>%d</size> "
#define FUU3 "<name>%s</name> </winner>"
#define FORMAT_WINNER HEADER_SOCKET FUU2 FUU3

static void	do_stuff(t_player *player, t_socket *socket)
{
	char			*s;
	unsigned char	*encoded_name __attribute__((cleanup(clean_simple_ptr)));
	size_t			olen;
	int32_t			len;

	encoded_name = encode_base64(
		player->header.prog_name, ft_strlen(player->header.prog_name), &olen);
	len = ft_asprintf(&s, FORMAT_PLAYER, player->id, olen, encoded_name);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
}

int			send_players(t_vm *vm)
{
	uint8_t	i;

	if (vm->socket.enable != ENABLE_SOCKET)
		return (0);
	i = 0;
	while (i < vm->players_count)
	{
		do_stuff(vm->players + i, &vm->socket);
		i++;
	}
	return (0);
}

int			send_winner(t_player *player, t_socket *socket)
{
	char			*s;
	unsigned char	*encoded_name __attribute__((cleanup(clean_simple_ptr)));
	size_t			olen;
	int32_t			len;

	encoded_name = NULL;
	if (socket->enable != ENABLE_SOCKET)
		return (0);
	encoded_name = encode_base64(
		player->header.prog_name, ft_strlen(player->header.prog_name), &olen);
	len = ft_asprintf(&s, FORMAT_WINNER, player->id, olen, encoded_name);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
	return (len);
}
