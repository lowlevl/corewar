/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taunt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:23:10 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/10 16:18:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FORMAT_TAUNT                                                           \
	HEADER_SOCKET "<aff> <playerId>%d</playerId> <msg>%s</msg> </aff>"

int send_taunt(t_socket *socket, t_process *process)
{
	int32_t len;
	char *  s;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	len = ft_asprintf(
		&s, FORMAT_TAUNT, process->player_id, process->taunt_buffer);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
	return len;
}
