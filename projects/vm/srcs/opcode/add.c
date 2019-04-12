/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 09:55:24 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/27 11:45:32 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int read_args_exec(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return -1;

	if (get_type_arg(oc, 1) == T_REG)
		args[1] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return -1;

	if (get_type_arg(oc, 2) == T_REG)
		args[2] = read_arg(process, mem, T_REG);
	else
		return -1;

	return 0;
}

void exec_add(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  oc;
	uint32_t args[3];
	uint32_t sum;

	(void)op;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE &&ft_dprintf(2, TYPE_TEMPLATE_3, get_type_arg(oc, 0),
		get_type_arg(oc, 1), get_type_arg(oc, 2));
	if (read_args_exec(vm->memory, process, args, oc) == 0)
	{
		sum = args[0] + args[1];
		DEBUG_R_FC &&ft_dprintf(
			2, FUNC_PREFIX "add %%%d %%%d r%d\n", args[0], args[1], args[2]);
		process->carry = sum == 0;
		write_in_registre(process, args[2], sum);
	}
	else
		process->carry = 1;
	DEBUG_CARRY &&ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
