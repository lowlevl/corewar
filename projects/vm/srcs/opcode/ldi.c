/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:50:02 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/03 14:49:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int read_args_exec(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	size_t  pos;
	uint8_t type_arg;

	pos = get_idx_in_memory(process) - 2;
	type_arg = get_type_arg(oc, 0);
	if (get_argument_all_restrict(
			(size_t[2]){type_arg, pos}, args, mem, process))
		return (-1);
	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_DIR)
		args[1] = read_arg(process, mem, T_DIR);
	else if (type_arg == T_REG)
		args[1] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return (-1);
	if (get_type_arg(oc, 2) == T_REG)
		args[2] = read_arg(process, mem, T_REG);
	else
		return (-1);
	return (0);
}

void exec_ldi(t_vm *vm, t_process *process, const t_op *op)
{
	int16_t  pos;
	uint8_t  oc;
	uint32_t args[3];
	int16_t  adr;

	(void)op;
	pos = get_idx_in_memory(process) - 1;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE &&ft_dprintf(2, TYPE_TEMPLATE_3, get_type_arg(oc, 0),
		get_type_arg(oc, 1), get_type_arg(oc, 2));
	if (read_args_exec(vm->memory, process, args, oc) == 0)
	{
		adr = args[0] + args[1];
		// process->carry = adr == 0;
		DEBUG_R_FC &&ft_dprintf(2, FUNC_P "ldi :(%hd + %hd = 0x%hx) r%d\n",
			pos, adr, get_restrict_address(pos, adr), args[2]);
		write_in_registre(
			process, args[2], get_indirect_restrict(pos, adr, vm->memory));
	}
	else
	{
		DEBUG_R_FC&&ft_dprintf(2, FUNC_P "ldi" BAD_ARG);
		process->carry = 1;
	}

	// DEBUG_CARRY &&ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
