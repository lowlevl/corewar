/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:52:54 by glodi             #+#    #+#             */
/*   Updated: 2019/03/12 13:29:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "opcode.h"

int get_type_arg(uint8_t co, uint8_t arg_number)
{
	arg_number = (MAX_ARGS_NUMBER - arg_number - 1) * 2;
	if ((co & 0b11 << arg_number) == (OC_REG << arg_number))
		return (T_REG);
	else if ((co & 0b11 << arg_number) == (OC_IND << arg_number))
		return (T_IND);
	else if ((co & 0b11 << arg_number) == (OC_DIR << arg_number))
		return (T_DIR);
	return -1;
}

uint16_t read_arg(uint8_t **pos, int type)
{
	uint16_t val;

	if (type == T_REG)
	{
		val = **pos;
		*pos = *pos + 1;
		return val;
	}
	else if (type == T_IND)
	{
		val = bswap_16(**(uint16_t **)pos);
		*pos = *pos + sizeof(val);
		return val;
	}
	else if (type == T_DIR)
	{
		val = bswap_16(**(uint16_t **)pos);
		*pos = *pos + sizeof(val);
		return val;
	}
	return -1;
}

uint32_t get_reg(t_process *process, uint8_t reg_idx)
{
	if (reg_idx < 1 || reg_idx >= REG_SIZE)
		return -1;
	return process->regs[reg_idx - 1];
}

uint8_t read_octet_code(uint8_t **pos)
{
	uint8_t octect_code;

	octect_code = **pos;
	*pos = *pos + 1;
	return octect_code;
}
