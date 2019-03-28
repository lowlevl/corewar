/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:55:00 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 16:37:28 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int send_message_to(t_sock_inter *dest, void *msg, size_t len)
{
	int rt;

	rt = send(dest->sock, msg, len, SOCK_SEND_FLAGS);
	if (rt < 0)
		perror("send()");
	return rt;
}

int send_message_to_all(t_socket *socket, void *msg, size_t len)
{
	size_t i;

	i = 0;
	while (socket->nb_client > i)
	{
		send_message_to(socket->clients + i, msg, len);
		i++;
	}
}
