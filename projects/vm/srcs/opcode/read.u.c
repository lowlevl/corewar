/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:24:36 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/25 14:46:52 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

uint8_t		read_octet_code(t_process *process, uint8_t *mem)
{
	uint8_t	octect_code;
	size_t	idx;

	idx = get_idx_in_memory(process);
	octect_code = mem[idx];
	process_move_cursor(process, 1);
	return (octect_code);
}

void		read_in_memory(
		uint8_t *memory, uint8_t *buffer, uint8_t len, size_t at)
{
	uint8_t	i;

	i = 0;
	while (i < len)
	{
		buffer[i] = memory[(i + at) % MEM_SIZE];
		i++;
	}
}

uint32_t	get_indirect(size_t current, size_t relative, uint8_t *memory)
{
	uint32_t	value;

	read_in_memory(memory, (uint8_t *)&value, 4, current + relative);
	DEBUG_GET && ft_dprintf(2,
		GET_PREFIX "read mem at(%hhx + %hhx = %hhx) get(%x)\n",
		current, relative, current + relative, value);
	return (BSWAP_32(value));
}

uint32_t	get_indirect_restrict(
		size_t current, size_t to_add, uint8_t *memory)
{
	return (get_indirect(current, to_add % IDX_MOD, memory));
}
