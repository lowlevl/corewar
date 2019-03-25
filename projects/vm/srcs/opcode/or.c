/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:44:00 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/25 11:29:25 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int read_arg_or(
	uint8_t *memory, t_process *process, uint32_t *args, uint8_t oc)
{
	uint8_t type_arg;
	size_t  pos;

	pos = get_idx_in_memory(process) - 2;
	type_arg = get_type_arg(oc, 0);
	if (type_arg == T_REG)
		args[0] = get_reg(process, read_arg(process, memory, T_REG));
	else if (type_arg == T_IND)
		args[0] = get_indirect_restrict(
			pos, read_arg(process, memory, T_IND), memory);
	else if (type_arg == T_DIR)
		args[0] = read_arg(process, memory, T_DIR_4);

	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_REG)
		args[1] = get_reg(process, read_arg(process, memory, T_REG));
	else if (type_arg == T_IND)
		args[1] = get_indirect_restrict(
			pos, read_arg(process, memory, T_IND), memory);
	else if (type_arg == T_DIR)
		args[1] = read_arg(process, memory, T_DIR_4);
	else
		return -1;

	if (get_type_arg(oc, 2) == T_REG)
		args[2] = read_arg(process, memory, T_REG);
	else
		return -1;

	return 0;
}

void exec_or(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  oc;
	uint32_t args[3];
	uint32_t logic;

	(void)op;
	ft_bzero(args, sizeof(args));
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE &&ft_dprintf(2, "type: %d %d %d\n", get_type_arg(oc, 0),
		get_type_arg(oc, 1), get_type_arg(oc, 2));
	if (read_arg_or(vm->memory, process, args, oc) == -1)
	{
		process->carry = 1;
	}
	else
	{
		logic = args[0] | args[1];
		process->carry = logic == 0;
		DEBUG_R_FC &&ft_dprintf(
			2, "or %%%b %%%b r%d\n", args[0], args[1], args[2]);
		write_in_registre(process, args[2], logic);
	}
	DEBUG_CARRY &&ft_dprintf(2, "carry: %d\n", process->carry);
}
