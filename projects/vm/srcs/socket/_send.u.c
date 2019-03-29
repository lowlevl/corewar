/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:55:00 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 09:01:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int send_message_to(t_sock_inter *dest, void *msg, socklen_t len)
{
	int rt;

	rt = send(dest->sock, msg, len, SOCK_SEND_FLAGS);
	if (rt < 0)
		perror("send()");
	return rt;
}

int send_message_to_all(t_socket *socket, void *msg, socklen_t len)
{
	int i;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	i = 0;
	while (socket->nb_client > i)
	{
		if (send_message_to(socket->clients + i, msg, len) < 0)
			return -1;
		i++;
	}
	return socket->nb_client;
}
