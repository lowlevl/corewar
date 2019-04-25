/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.2.u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:05:03 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/25 10:19:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static uint32_t	read_ind(t_process *process, uint8_t *mem, size_t idx, int type)
{
	uint16_t buff;

	process_move_cursor(process, 2);
	read_in_memory(mem, (uint8_t *)&buff, 2, idx);
	DEBUG_READ && ft_dprintf(
		2, READ_TEMPLATE, idx, type, BSWAP_16((uint16_t)buff));
	return (BSWAP_16(buff));
}

static uint32_t	read_dir(t_process *process, uint8_t *mem, size_t idx, int type)
{
	uint16_t buff;

	process_move_cursor(process, 2);
	read_in_memory(mem, (uint8_t *)&buff, 2, idx);
	DEBUG_READ && ft_dprintf(
		2, READ_TEMPLATE, idx, type, BSWAP_16((uint16_t)buff));
	return (BSWAP_16(buff));
}

uint32_t		read_arg(t_process *process, uint8_t *mem, int type)
{
	size_t		idx;
	uint32_t	buff;

	idx = get_idx_in_memory(process);
	if (type == T_REG)
	{
		process_move_cursor(process, 1);
		DEBUG_READ && ft_dprintf(2, READ_TEMPLATE, idx, type, mem[idx]);
		return (mem[idx]);
	}
	else if (type == T_IND)
		return (read_ind(process, mem, idx, type));
	else if (type == T_DIR)
		return (read_dir(process, mem, idx, type));
	else if (type == T_DIR_4)
	{
		process_move_cursor(process, 4);
		read_in_memory(mem, (uint8_t *)&buff, 4, idx);
		DEBUG_READ && ft_dprintf(2, READ_TEMPLATE, idx, type, BSWAP_32(buff));
		return (BSWAP_32(buff));
	}
	DEBUG_READ && ft_dprintf(2, READ_TEMPLATE_NOT, type);
	return (-1);
}
