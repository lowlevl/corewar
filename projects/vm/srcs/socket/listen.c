/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:02:24 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 09:00:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int set_listen_socket(t_socket *sock)
{
	int rt;

	if (sock->enable != ENABLE_SOCKET)
		return 0;
	rt = listen(sock->server.sock, MAX_CLIENT_SOCKET);
	if (rt < 0)
		perror("listen()");
	return rt;
}
