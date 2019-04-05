/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:32:12 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/05 16:43:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define CYCLE_FORMAT                                                           \
	HEADER_SOCKET "<cycle><current>%d</current><check>%d</check></cyle>"

int send_cycle(t_socket *socket, t_vm *vm)
{
    int32_t len;
    char *s;

    if (socket->enable != ENABLE_SOCKET)
        return 0;
    len = ft_asprintf(&s, CYCLE_FORMAT, vm->cycle_count, vm->next_check);
    if (s && len > 0)
    {
        ft_memcpy(s, &len, sizeof(len));
        send_message_to_all(socket, s, len);
        free(s);
    }
    return len;
}
