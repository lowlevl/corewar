/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:04:57 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 16:06:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int bind_setup_inter(t_sock_inter *server)
{
	int rt;

	rt =
		bind(server->sock, (t_sockaddr *)&server->inter, sizeof(t_sockaddr_in));
	if (rt < 0)
		perror("bind()");
	return rt;
}
