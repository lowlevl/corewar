/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:13:55 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 18:41:05 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

#define SOCKET "ip       : %s\nport     : %hu\nenable   : %hhu\nnb_client: %u\n"

int	debug_socket(t_socket *sock)
{
	if (sock)
	{
		return (ft_dprintf(
			2, SOCKET, sock->ip, sock->port, sock->enable, sock->nb_client));
	}
	return (0);
}
