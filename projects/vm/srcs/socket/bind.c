/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:04:57 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 08:59:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int bind_setup_inter(t_socket *sock)
{
	int rt;

	if (sock->enable != ENABLE_SOCKET)
		return 0;
	rt =
		bind(sock->server.sock, (t_sockaddr *)&sock->server.inter, sizeof(t_sockaddr_in));
	if (rt < 0)
		perror("bind()");
	return rt;
}
