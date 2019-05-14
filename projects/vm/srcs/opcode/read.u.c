/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:24:36 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 13:04:33 by glodi            ###   ########.fr       */
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

uint32_t	get_indirect(int16_t current, int16_t relative, uint8_t *memory)
{
	uint32_t	value;

	read_in_memory(
		memory, (uint8_t *)&value, 4, get_address(current, relative));
	DEBUG_GET && ft_dprintf(2,
		GET_PREFIX "read mem at(%hhx + %hhx = %hhx) get(%x)\n", current,
		relative, get_address(current, relative), value);
	return (BSWAP_32(value));
}

uint32_t	get_indirect_restrict(
		int16_t current, int16_t to_add, uint8_t *memory)
{
	uint32_t	value;

	read_in_memory(
		memory, (uint8_t *)&value, 4, get_restrict_address(current, to_add));
	DEBUG_GET && ft_dprintf(2,
		GET_PREFIX "read restrict mem at(%hd + %hd = 0x%hx) get(%x)\n",
		current, to_add, get_restrict_address(current, to_add), value);
	return (BSWAP_32(value));
}
