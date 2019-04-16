/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:23:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 14:03:59 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"

#define FU "<map> <idx>%zu</idx> <size>%zu</size> <heat>%s</heat> </map>"
#define FORMAT_MAP HEADER_SOCKET FU

int	send_all_map(t_vm *vm)
{
	return (send_map_chunk(vm, 0, MEM_SIZE));
}

int	send_map_chunk(t_vm *vm, size_t idx, size_t chunk_size)
{
	char			*s;
	void			*map64 __attribute__((cleanup(clean_simple_ptr)));
	size_t			map64_len;
	int32_t			len;

	if (vm->socket.enable != ENABLE_SOCKET)
		return (0);
	map64 = encode_base64(vm->heat_map + idx, chunk_size, &map64_len);
	len = ft_asprintf(&s, FORMAT_MAP, idx, chunk_size, map64);
	if (s && len > 0)
	{
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(&vm->socket, s, len);
		free(s);
	}
	return (len);
}
