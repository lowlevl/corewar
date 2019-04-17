/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:52:45 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 13:43:27 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int	read_args_lld(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	uint8_t	type_arg;
	size_t	pos;

	pos = get_idx_in_memory(process) - 2;
	type_arg = get_type_arg(oc, 0);
	if (type_arg == T_IND)
		args[0] = get_indirect(pos, read_arg(process, mem, T_IND), mem);
	else if (type_arg == T_DIR)
		args[0] = read_arg(process, mem, T_DIR_4);
	else
		return (-1);
	if (get_type_arg(oc, 1) == T_REG)
		args[1] = read_arg(process, mem, T_REG);
	else
		return (-1);
	return (0);
}

void		exec_lld(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t		oc;
	uint32_t	args[2];

	(void)op;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE && ft_dprintf(
		2, TYPE_TEMPLATE_2, get_type_arg(oc, 0), get_type_arg(oc, 1));
	if (read_args_lld(vm->memory, process, args, oc) == 0)
	{
		process->carry = args[0] == 0;
		DEBUG_R_FC && ft_dprintf(
				2, FUNC_PREFIX "lld %%%x r%d\n", args[0], args[1]);
		write_in_registre(process, args[1], args[0]);
	}
	else
		process->carry = 1;
	DEBUG_CARRY && ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
