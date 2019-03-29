/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taunt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:23:10 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 15:29:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.h"

#define FORMAT_TAUNT "<aff><playerId>%d</playerId><msg>%s</msg></aff>"

int send_taunt(t_socket *socket, t_process *process)
{
	size_t len;
	char * s;

	if (socket->enable != ENABLE_SOCKET)
		return 0;
	process->taunt_buffer[process->taunt_size] = 0;
	len = ft_asprintf(
		&s, FORMAT_TAUNT, process->player_id, process->taunt_buffer);
	if (s && len > 0)
	{
		send_message_to_all(socket, s, len);
		free(s);
	}
}
