/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 09:09:44 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 09:23:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int close_clients(t_socket *sock)
{
	int i;

	i = 0;
	while (i < sock->nb_client)
	{
		close(sock->clients[i].sock);
		i++;
	}
	sock->nb_client = 0;
	return (0);
}

int disable_socket(t_socket *sock)
{

	if (sock->enable != ENABLE_SOCKET)
		return 0;
	shutdown(sock->server.sock, SHUT_RDWR);
	close_clients(sock);
	close(sock->server.sock);
	sock->enable = DISABLE_SOCKET;
	return 0;
}
