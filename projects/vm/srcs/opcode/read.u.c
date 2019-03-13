/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:24:36 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 13:08:10 by fbenneto         ###   ########.fr       */
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

uint16_t read_arg(t_process *process, uint8_t *mem, int type)
{
	size_t idx;

	idx = get_idx_in_memory(process);
	if (type == T_REG)
	{
		process_move_cursor(process, 1);
		return mem[idx];
	}
	else if (type == T_IND)
	{
		process_move_cursor(process, 2);
		return bswap_16(*(uint16_t *)(mem + idx));
	}
	else if (type == T_DIR)
	{
		process_move_cursor(process, 2);
		return bswap_16(*(uint16_t *)(mem + idx));
	}
	else if (type == T_DIR_4)
	{
		process_move_cursor(process, 4);
		return bswap_32(*(uint32_t *)(mem + idx));
	}
	return -1;
}
