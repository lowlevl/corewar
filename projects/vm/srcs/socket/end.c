/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:31:54 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 13:25:56 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define END_FORMAT HEADER_SOCKET "<end />"

int	send_end(t_socket *socket)
{
	int32_t	len;
	char	*s;

	if (socket->enable != ENABLE_SOCKET)
		return (0);
	len = ft_asprintf(&s, END_FORMAT);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(socket, s, len);
		free(s);
	}
	return (len);
}
