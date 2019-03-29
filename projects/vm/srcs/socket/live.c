/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:33:16 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 15:36:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

#define FORMAT_LIVE "<live>%d</live>"

int send_live(t_socket *socket, int32_t player_id)
{
	size_t len;
	char *s;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	ft_asprintf(&s, FORMAT_LIVE, player_id);
	if (s && len > 0)
	{
		send_message_to_all(socket, s, len);
		free(s);
	}
}
