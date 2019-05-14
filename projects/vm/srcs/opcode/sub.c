/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 09:55:24 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 11:59:40 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int	read_args_exec(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return (-1);
	if (get_type_arg(oc, 1) == T_REG)
		args[1] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return (-1);
	if (get_type_arg(oc, 2) == T_REG)
		args[2] = read_arg(process, mem, T_REG);
	else
		return (-1);
	return (0);
}

void		exec_sub(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t		oc;
	uint32_t	args[3];
	uint32_t	sub;

	(void)op;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE && ft_dprintf(2, TYPE_TEMPLATE_3, get_type_arg(oc, 0),
		get_type_arg(oc, 1), get_type_arg(oc, 2));
	if (read_args_exec(vm->memory, process, args, oc) == 0)
	{
		sub = args[0] - args[1];
		process->carry = sub == 0;
		DEBUG_R_FC && ft_dprintf(
			2, FUNC_P "sub %%%d %%%d r%d = %d\n",
			args[0], args[1], args[2], sub);
		write_in_registre(process, args[2], sub);
	}
	else
	{
		DEBUG_R_FC && ft_dprintf(2, FUNC_P "sub" BAD_ARG);
		process->carry = 1;
	}
	DEBUG_CARRY && ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
