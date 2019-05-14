/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:32:12 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/06 11:36:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FU1 "<cycle> <current>%d</current> <check>%d</check> "
#define FU2 "<die>%d</die> <ncheck>%d</ncheck> <live>%d</live> </cycle>"
#define CYCLE_FORMAT HEADER_SOCKET FU1 FU2

int	send_cycle(t_socket *socket, t_vm *vm)
{
	int32_t	len;
	char	*s;

	if (socket->enable != ENABLE_SOCKET)
		return (0);
	len = ft_asprintf(&s, CYCLE_FORMAT, vm->cycle_count, vm->next_check,
		vm->cycle_to_die, vm->nb_check, vm->nb_live_for_cycle);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
	return (len);
}
