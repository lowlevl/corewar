/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:50:02 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/03 09:38:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int	read_args_exec(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	size_t	pos;
	uint8_t	type_arg;

	pos = get_idx_in_memory(process) - 1;
	type_arg = get_type_arg(oc, 0);
	if (type_arg == T_REG)
		args[0] = get_reg(process, read_arg(process, mem, T_REG));
	else if (type_arg == T_DIR)
		args[0] = read_arg(process, mem, T_DIR);
	else if (type_arg == T_IND)
		args[0] = get_indirect(pos, read_arg(process, mem, T_IND), mem);
	else
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

void		exec_lldi(t_vm *vm, t_process *process, const t_op *op)
{
	size_t		pos;
	uint8_t		oc;
	uint32_t	args[3];
	uint32_t	adr;

	(void)op;
	pos = get_idx_in_memory(process) - 1;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE && ft_dprintf(2, TYPE_TEMPLATE_3, get_type_arg(oc, 0),
		get_type_arg(oc, 1), get_type_arg(oc, 2));
	if (read_args_exec(vm->memory, process, args, oc) == 0)
	{
		adr = args[0] + args[1];
		process->carry = adr == 0;
		DEBUG_R_FC && ft_dprintf(2, FUNC_P "lldi (%x + %x = %x), r%d\n",
				pos, adr, pos + adr, args[2]);
		write_in_registre(process, args[2], get_indirect(pos, adr, vm->memory));
	}
	else
	{
		DEBUG_R_FC&&ft_dprintf(2, FUNC_P "lldi" BAD_ARG_OC, oc);
		ft_dprintf(2, "cursor pos %hx\n", get_idx_in_memory(process));
		print_memory(vm->memory, vm->heat_map);
		process->carry = 1;
	}

	DEBUG_CARRY && ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
