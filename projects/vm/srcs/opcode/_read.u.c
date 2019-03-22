/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _read.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:24:36 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/22 15:52:48 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

uint8_t read_octet_code(t_process *process, uint8_t *mem)
{
	uint8_t octect_code;
	size_t  idx;

	idx = get_idx_in_memory(process);
	octect_code = mem[idx];
	process_move_cursor(process, 1);
	return octect_code;
}

void read_in_memory(uint8_t *memory, uint8_t *buffer, uint8_t len, size_t at)
{
	uint8_t i;

	i = 0;
	while (i < len)
	{
		buffer[i] = memory[(i + at) % MEM_SIZE];
		i++;
	}
}

uint32_t read_arg(t_process *process, uint8_t *mem, int type)
{
	size_t   idx;
	uint32_t buff;

	idx = get_idx_in_memory(process);
	DEBUG_READ &&ft_dprintf(2, "read mem: idx: %.2x, type: %d", idx, type);
	if (type == T_REG)
	{
		process_move_cursor(process, 1);
		DEBUG_READ &&ft_dprintf(2, ", val: %.2x\n", mem[idx]);
		return mem[idx];
	}
	else if (type == T_IND)
	{
		process_move_cursor(process, 2);
		read_in_memory(mem, (uint8_t *)&buff, 2, idx);
		DEBUG_READ &&ft_dprintf(2, ", val: %.2x\n", bswap_16((uint16_t)buff));
		return bswap_16((uint16_t)buff);
	}
	else if (type == T_DIR)
	{
		process_move_cursor(process, 2);
		read_in_memory(mem, (uint8_t *)&buff, 2, idx);
		DEBUG_READ &&ft_dprintf(2, ", val: %.2x\n", bswap_16((uint16_t)buff));
		return bswap_16((uint16_t)buff);
	}
	else if (type == T_DIR_4)
	{
		process_move_cursor(process, 4);
		read_in_memory(mem, (uint8_t *)&buff, 4, idx);
		DEBUG_READ &&ft_dprintf(2, ", val: %.2x\n", bswap_32(buff));
		return bswap_32(buff);
	}
	DEBUG_READ &&ft_dprintf(2, " > type not found\n");
	return -1;
}

uint32_t get_indirect(size_t current, size_t relative, uint8_t *memory)
{
	return bswap_32(*(uint32_t *)(memory + ((current + relative) % MEM_SIZE)));
}

uint32_t get_indirect_restrict(size_t current, size_t to_add, uint8_t *memory)
{
	return get_indirect(current, to_add % IDX_MOD, memory);
}
