/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:33:16 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/05 16:12:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FORMAT_LIVE HEADER_SOCKET "<live>%d</live>"

int send_live(t_socket *socket, int32_t player_id)
{
	int32_t len;
	char *s;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	len = ft_asprintf(&s, FORMAT_LIVE, player_id);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
	return 0;
}
