/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:45:36 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/05 16:01:40 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "proc.h"
#include "socket.h"

#define FORMAT_PROC                                                            \
	HEADER_SOCKET "<proc><id>%d</id><playerId>%d</playerId><pos>%d</pos></"    \
				  "proc>"

static void do_stuff(t_process *proc, t_socket *socket)
{
	char *  s;
	int32_t len;

	len = ft_asprintf(
		&s, FORMAT_PROC, proc->id, proc->player_id, get_idx_in_memory(proc));
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		s[len] = 0;
		// DEBUG_SOCKET_SEND &&ft_dprintf(2, SOCKET_SEND, len, s);
		send_message_to_all(socket, s, len);
		free(s);
	}
}

int send_procs(t_vm *vm)
{
	t_process *node;

	if (vm->socket.enable != ENABLE_SOCKET)
		return 0;
	node = vm->processes;
	while (node)
	{
		do_stuff(node, &vm->socket);
		node = node->next;
	}
	return 0;
}
