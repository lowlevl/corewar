/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _send.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:55:00 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 12:15:15 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define REPLY_MAX_LEN 2

int	send_message_to(t_sock_inter *dest, void *msg, socklen_t len)
{
	int	rt;

	if (dest->disable == 1)
		return (0);
	rt = send(dest->sock, msg, len, SOCK_SEND_FLAGS);
	if (rt < 0)
	{
		dest->disable = 1;
		perror("send()");
	}
	return (rt);
}

int	get_reply(t_sock_inter *dest)
{
	char	reply[REPLY_MAX_LEN + 1];
	int		recv_bit;

	if (dest->disable == 1)
		return (0);
	if ((recv_bit = recv(dest->sock, reply, REPLY_MAX_LEN, 0)) < 0)
	{
		dest->disable = 1;
		perror("recv()");
		return (recv_bit);
	}
	reply[recv_bit] = 0;
	DEBUG_SOCKET_RECV && ft_dprintf(2, SOCKET_RECV, reply, recv_bit);
	if (ft_strcmp("ok", reply) == 0)
		dest->disable = 1;
	return (recv_bit);
}

int	send_message_to_all(t_socket *socket, void *msg, socklen_t len)
{
	int i;

	if (socket->enable != ENABLE_SOCKET)
		return (0);
	DEBUG_SOCKET_SEND && ft_dprintf(2, SOCKET_SEND, len, msg, len);
	i = 0;
	while (socket->nb_client > i)
	{
		if (send_message_to(socket->clients + i, msg, len) < 0)
			return (-1);
		i++;
	}
	i = 0;
	if (SOCKET_SYNC)
	{
		while (socket->nb_client > i)
		{
			if (get_reply(socket->clients + i) < 0)
				return (-1);
			i++;
		}
	}
	return (socket->nb_client);
}
