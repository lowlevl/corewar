/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:15:12 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 13:23:52 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int	create_server_socket(t_socket *server)
{
	int	sock;

	if (server->enable != ENABLE_SOCKET)
		return (0);
	DEBUG_SOCKET_SETUP && ft_dprintf(2, SOCKET_CREATE);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("socket()");
		return (sock);
	}
	server->server.sock = sock;
	return (sock);
}

int	setup_server_socket(t_socket *server)
{
	int	rt;
	int	option;

	if (server->enable != ENABLE_SOCKET)
		return (0);
	DEBUG_SOCKET_SETUP && ft_dprintf(2, SOCKET_SETUP);
	option = ALLOW_REUSE_ADDR;
	rt = setsockopt(
		server->server.sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
	if (rt < 0)
		perror("setsockopt()");
	return (rt);
}
