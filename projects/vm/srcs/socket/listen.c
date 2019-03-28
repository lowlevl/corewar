/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:02:24 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 16:03:51 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int set_listen_socket(t_sock_inter *server)
{
	int rt;

	rt = listen(server->sock, MAX_CLIENT_SOCKET);
	if (rt < 0)
		perror("listen()");
	return rt;
}
