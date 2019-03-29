/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:13:55 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 10:20:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void debug_socket(t_socket *sock)
{
	if (sock)
	{
		ft_dprintf(2, "ip        : %s\n", sock->ip);
		ft_dprintf(2, "port      : %hu\n", sock->port);
		ft_dprintf(2, "enable    : %hhu\n", sock->enable);
		ft_dprintf(2, "nb_client : %u\n", sock->nb_client);
	}
}
