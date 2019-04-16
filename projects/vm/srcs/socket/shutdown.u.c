/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _shutdown.u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 09:09:44 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 12:18:11 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int	close_clients(t_socket *sock)
{
	int	i;

	DEBUG_SOCKET_SETUP && ft_dprintf(2, SOCKET_CLOSE);
	i = 0;
	while (i < sock->nb_client)
	{
		close(sock->clients[i].sock);
		i++;
	}
	sock->nb_client = 0;
	return (0);
}

int	disable_socket(t_socket *sock)
{
	if (sock->enable != ENABLE_SOCKET)
		return (0);
	DEBUG_SOCKET_SETUP && ft_dprintf(2, SOCKET_SHUTDOWN);
	close_clients(sock);
	close(sock->server.sock);
	sock->enable = DISABLE_SOCKET;
	return (0);
}
