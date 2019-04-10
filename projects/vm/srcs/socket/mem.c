/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:23:19 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/10 13:10:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "socket.h"


#define FORMAT_MEM HEADER_SOCKET "<mem><idx>%zu</idx><size>%zu</size><bytes>%s</bytes></mem>"
// #define FORMAT_MEM HEADER_SOCKET "<mem><idx>%zu</idx><size>%zu</size><bytes>#%*d</bytes></mem>"

int send_all_mem(t_vm *vm)
{
	return send_mem_chunk(vm, 0, MEM_SIZE);
}

int send_mem_chunk(t_vm *vm, size_t idx, size_t chunk_size)
{
	char *s;
	AUTO_CLEAN void *mem64;
	size_t mem64_size;
	int32_t len;

	if (vm->socket.enable != ENABLE_SOCKET)
		return 0;
	mem64 = encode_base64(vm->memory + idx, chunk_size, &mem64_size);
	// len = ft_asprintf(&s, FORMAT_MEM, idx, chunk_size, chunk_size, 0);
	len = ft_asprintf(&s, FORMAT_MEM, idx, chunk_size, mem64);
	if (s && len > 0)
	{
		// ft_memcpy(ft_strchr(s, '#') + 1, mem64, mem64_size);
		ft_memcpy(s, &len, sizeof(len));
		send_message_to_all(&vm->socket, s, len);
		free(s);
	}
	return len;
}
