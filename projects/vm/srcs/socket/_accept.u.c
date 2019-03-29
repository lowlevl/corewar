/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _accept.u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:58:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 12:14:41 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int accept_new_connexion(t_socket *socket)
{
	t_sock_inter *server;
	t_sock_inter *empty_inter;
	socklen_t	 len;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	len = sizeof(t_sockaddr_in);
	server = &socket->server;
	if (socket->nb_client >= MAX_CLIENT_SOCKET)
	{
		errno = ENOMEM;
		perror("cannot accept more connexion");
		return -1;
	}
	empty_inter = socket->clients + socket->nb_client;
	empty_inter->sock =
		accept(server->sock, (t_sockaddr *)&empty_inter->inter, &len);
	DEBUG_SOCKET_CO &&ft_dprintf(2, SOCKET_NEW_CO, empty_inter->inter.sin_addr,
			empty_inter->inter.sin_port);
	if (empty_inter->sock < 0)
		perror("accept()");
	else
		socket->nb_client++;
	return empty_inter->sock;
}

static void err_select(t_socket *sock)
{
	perror("select()");
	disable_socket(sock);
}

static int wrap_select(t_socket *sock, fd_set *readfd)
{
	t_timeout tm;

	tm.tv_sec = TIMEOUT_SEC;
	tm.tv_usec = TIMEOUT_USEC;
	DEBUG_SOCKET_CO &&ft_dprintf(2, SOCKET_WAITING, tm.tv_sec, tm.tv_usec);
	return select(sock->server.sock + 1, readfd, NULL, NULL, &tm);
}

int accept_all_client(t_socket *sock)
{
	int	i;
	fd_set readfd;
	int	rt;

	if (sock->enable != ENABLE_SOCKET)
		return 0;
	FD_ZERO(&readfd);
	FD_SET(sock->server.sock, &readfd);
	i = 0;
	while (i < MAX_CLIENT_SOCKET)
	{
		rt = wrap_select(sock, &readfd);
		if (rt > 0)
			accept_new_connexion(sock);
		else
		{
			if (rt == 0)
				DEBUG_SOCKET_CO &&ft_dprintf(2, SOCKET_TIMEOUT);
			else
				err_select(sock);
			break;
		}
		i++;
	}
	return sock->nb_client;
}
