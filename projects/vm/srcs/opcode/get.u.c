/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:52:54 by glodi             #+#    #+#             */
/*   Updated: 2019/04/30 19:27:53 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

int			get_type_arg(uint8_t octet_code, uint8_t arg_number)
{
	arg_number = (MAX_ARGS_NUMBER - arg_number - 1) * 2;
	if ((octet_code & 0b11 << arg_number) == (REG_CODE << arg_number))
		return (T_REG);
	else if ((octet_code & 0b11 << arg_number) == (DIR_CODE << arg_number))
		return (T_DIR);
	else if ((octet_code & 0b11 << arg_number) == (IND_CODE << arg_number))
		return (T_IND);
	return (-1);
}

uint32_t	get_reg(t_process *process, uint8_t reg_idx)
{
	if (reg_idx < 1 || reg_idx >= REG_NUMBER)
	{
		DEBUG_GET && ft_dprintf(2, GET_TEMPLATE_REG_NOT, reg_idx - 1);
		return (-1);
	}
	DEBUG_GET != 0 && ft_dprintf(2, GET_TEMPLATE_REG, reg_idx - 1,
		process->regs[reg_idx - 1]);
	return (process->regs[reg_idx - 1]);
}
