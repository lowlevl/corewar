/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:44:00 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 11:55:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int read_and_arg(
	uint8_t *memory, t_process *process, uint32_t *args, uint8_t oc)
{
	uint8_t type_arg;

	type_arg = get_type_arg(oc, 0);
	if (type_arg == T_REG)
		args[0] = get_reg(process, read_arg(process, memory, T_REG));
	else if (type_arg == T_IND)
		args[0] = get_indirect(
			get_idx_in_memory(process) + read_arg(process, memory, T_IND),
			memory);
	else if (type_arg == T_DIR)
		args[0] = read_arg(process, memory, T_DIR_4);

	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_REG)
		args[1] = get_reg(process, read_arg(process, memory, T_REG));
	else if (type_arg == T_IND)
		args[1] = get_indirect(
			get_idx_in_memory(process) + read_arg(process, memory, T_IND),
			memory);
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

void exec_and(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  oc;
	uint32_t args[3];
	uint32_t logic;

	(void)op;
	ft_bzero(args, sizeof(args));
	oc = read_octet_code(process, vm->memory);
	ft_printf("type: %d %d %d\n", get_type_arg(oc, 0), get_type_arg(oc, 1),
		get_type_arg(oc, 2));
	if (read_and_arg(vm->memory, process, args, oc) == -1 ||
		(logic = args[0] & args[1]) == 0)
	{
		process->carry = 1;
	}
	else
	{
		write_in_registre(process, args[2], logic);
	}
	ft_printf("args[0]: %u\n", args[0]);
	ft_printf("args[1]: %u\n", args[1]);
	ft_printf("args[2]: %u\n", args[2]);
}
