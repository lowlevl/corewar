/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:58:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 16:01:40 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

int accept_new_connexion(t_sock_inter *server, t_sock_inter *empty_inter)
{
	const socklen_t len = sizeof(t_sockaddr_in);

	empty_inter->sock =
		accept(server->sock, (t_sockaddr *)&empty_inter->inter, &len);
	if (empty_inter->sock < 0)
		perror("accept()");
	return empty_inter->sock;
}
