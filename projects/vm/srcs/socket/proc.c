/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:45:36 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/12 15:20:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "libft.h"
#include "socket.h"

#define INFO_PROC                                                              \
	HEADER_SOCKET                                                              \
	"<proc> <id>%d</id> <playerId>%d</playerId> <pos>%d</pos> </proc>"

#define DEAD_PROC                                                              \
	HEADER_SOCKET "<dead> <id>%d</id> <playerId>%d</playerId> </dead>"

static void do_stuff(t_process *proc, t_socket *socket)
{
	char *  s;
	int32_t len;

	len = ft_asprintf(
		&s, INFO_PROC, proc->id, proc->player_id, get_idx_in_memory(proc));
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		// DEBUG_SOCKET_SEND &&ft_dprintf(2, SOCKET_SEND, len, s);
		send_message_to_all(socket, s, len);
		free(s);
	}
}

int send_dead_proc(t_socket *sock, t_process *proc)
{
	AUTO_CLEAN char *s;
	int32_t			 len;

	len = ft_asprintf(&s, DEAD_PROC, proc->id, proc->player_id);
	if (s && len > 0) {
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(sock, s, len);
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
	return 1;
}
