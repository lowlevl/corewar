/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:29:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/01 15:02:23 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int read_args_st(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	size_t  pos;
	uint8_t type_arg;

	pos = get_idx_in_memory(process) - 2;

	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return -1;

	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_REG)
		args[1] = read_arg(process, mem, T_REG);
	else if (type_arg == T_IND)
	{
		args[1] = read_arg(process, mem, T_IND);
	}
	else
		return -1;

	return 0;
}

void exec_st(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  oc;
	size_t   pos;
	uint32_t args[2];

	(void)op;
	pos = get_idx_in_memory(process) - 1;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE &&ft_dprintf(
		2, TYPE_TEMPLATE_2, get_type_arg(oc, 0), get_type_arg(oc, 1));
	if (read_args_st(vm->memory, process, args, oc) == 0)
	{
		process->carry = args[0] == 0;
		if (get_type_arg(oc, 1) == T_REG)
		{
			DEBUG_R_FC &&ft_dprintf(
				2, FUNC_PREFIX "st %%%d r%d\n", args[0], args[1]);
			write_in_registre(process, args[1], args[0]);
		}
		else if (get_type_arg(oc, 1) == T_IND)
		{
			DEBUG_R_FC &&ft_dprintf(2,
				FUNC_PREFIX "st %%%d :(%.2hx + %.2hx = %.2hx)\n", args[0],
				pos, args[1], get_restrict_address(pos, args[1]));

			args[0] = bswap_32(args[0]);
			write_in_mem_wrapper(vm, process, (uint8_t *)args,
				(t_coord){get_restrict_address(pos, args[1]), sizeof(*args)});
		}
	}
	DEBUG_CARRY &&ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
