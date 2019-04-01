/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _write.u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:26:13 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/01 10:32:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heat_map.h"
#include "opcode.h"

static inline size_t get_index(size_t i)
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
	if (reg_idx < 1 || reg_idx > REG_NUMBER)
	{
		DEBUG_WRITE &&ft_dprintf(
			2, "write reg: id: %d not in bound\n", reg_idx - 1);
		return;
	}
	DEBUG_WRITE &&ft_dprintf(
		2, "write reg: id: %d, val: %x\n", reg_idx - 1, value);
	process->regs[reg_idx - 1] = value;
}

void write_in_mem_wrapper(
	t_vm *vm, t_process *proc, uint8_t *content, t_coord coord)
{
	write_in_memory(vm->memory, content, coord.len, coord.at);
	assign_player_to_area(vm->heat_map, 5, coord.at, coord.len);
}
