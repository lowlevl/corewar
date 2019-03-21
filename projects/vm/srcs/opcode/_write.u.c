/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _write.u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:26:13 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/21 16:21:08 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static size_t get_index(size_t i)
{
	return i % MEM_SIZE;
}

void write_in_memory(uint8_t *mem, uint8_t *content, size_t len, size_t at)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		mem[get_index(at + i)] = content[i];
		i++;
	}
}

void write_in_memory_restrict(
	uint8_t *mem, uint8_t *content, size_t len, size_t at)
{
	return write_in_memory(mem, content, len, at % IDX_MOD);
}

void write_in_registre(t_process *process, uint16_t reg_idx, uint32_t value)
{
	DEBUG_WRITE &&ft_dprintf(
		2, "write reg: id: %d, val: %x\n", reg_idx - 1, value);
	if (reg_idx < 1 || reg_idx > REG_NUMBER)
		return;
	process->regs[reg_idx - 1] = value;
}
