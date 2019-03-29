/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:07:47 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 10:30:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int setup_server_interface(t_socket *socket)
{
	t_sock_inter *server;
	int			  rt;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	server = &socket->server;
	server->inter.sin_port = htons(socket->port);
	rt = inet_aton(socket->ip, &server->inter.sin_addr);
	SOCKET_SETUP &&ft_dprintf(2, SOCKET_INTERFACE, socket->ip, socket->port,
		server->inter.sin_port, server->inter.sin_addr);
	if (rt == 0)
		perror("inet_aton()");
	return rt;
}
