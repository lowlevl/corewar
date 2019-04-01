/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _send.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:55:00 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/01 16:56:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int send_message_to(t_sock_inter *dest, void *msg, socklen_t len)
{
	int rt;
	char test;

	rt = send(dest->sock, msg, len, SOCK_SEND_FLAGS);
	if (rt < 0)
		perror("send()");
	SOCKET_SYNC && recv(dest->sock, &test, 1, 0);
	return rt;
}

int send_message_to_all(t_socket *socket, void *msg, socklen_t len)
{
	int i;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	DEBUG_SOCKET_SEND &&ft_dprintf(2, SOCKET_SEND, len, msg);
	i = 0;
	while (socket->nb_client > i)
	{
		if (send_message_to(socket->clients + i, msg, len) < 0)
			return -1;
		i++;
	}
	return socket->nb_client;
}
