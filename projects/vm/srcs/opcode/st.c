/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:29:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/22 13:14:25 by fbenneto         ###   ########.fr       */
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
		args[1] = read_arg(process, mem, T_IND);
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
	if (read_args_st(vm->memory, process, args, oc) == 0)
	{
		process->carry = args[0] == 0;
		if (get_type_arg(oc, 1) == T_REG)
		{
			DEBUG_R_FC &&ft_dprintf(2, "st %%%d r%d\n", args[0], args[1]);
			write_in_registre(process, args[1], args[0]);
		}
		else
		{
			DEBUG_R_FC &&ft_dprintf(2, "st %%%d :%x\n", args[0], get_restrict_address(pos, args[1]));
			args[0] = bswap_32(args[0]);
			write_in_memory(vm->memory, (uint8_t *)args, sizeof(*args),
				get_restrict_address(pos, args[1]));
		}
	}
}
