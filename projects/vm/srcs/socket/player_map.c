/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:23:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/05 16:38:14 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FORMAT_MAP HEADER_SOCKET "<map><idx>%zu</idx><size>%zu</size><heat>#%*d</heat></map>"

int send_all_map(t_vm *vm)
{
	return send_map_chunk(vm, 0, MEM_SIZE);
}

int send_map_chunk(t_vm *vm, size_t idx, size_t chunk_size)
{
	char * s;
	int32_t len;

	if (vm->socket.enable != ENABLE_SOCKET)
		return 0;
	len = ft_asprintf(&s, FORMAT_MAP, idx, chunk_size, chunk_size, 0);
	if (s && len > 0)
	{
		ft_memcpy(ft_strchr(s, '#') + 1, vm->heat_map + idx, chunk_size);
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(&vm->socket, s, len);
		free(s);
	}
	return len;
}
