/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:27:51 by glodi             #+#    #+#             */
/*   Updated: 2019/04/30 21:23:23 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int	read_sti_arg(
	uint8_t *memory, t_process *process, uint32_t *args, uint8_t oc)
{
	uint8_t type_arg;
	size_t	pos;

	pos = get_idx_in_memory(process) - 2;
	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(process, memory, T_REG));
	else
		return (-1);
	type_arg = get_type_arg(oc, 1);
	if (get_argument_all_restrict(
		(size_t[2]){ type_arg, pos }, args + 1, memory, process))
		return (-1);
	type_arg = get_type_arg(oc, 2);
	if (type_arg == T_IND)
		args[2] = get_indirect_restrict(
			pos, read_arg(process, memory, T_IND), memory);
	else if (type_arg == T_DIR)
		args[2] = read_arg(process, memory, T_DIR);
	else
		return (-1);
	return (0);
}

void		exec_sti(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t		oc;
	uint16_t		pos;
	uint32_t	args[3];
	uint16_t	adr;

	(void)op;
	ft_bzero(args, sizeof(args));
	pos = get_idx_in_memory(process) - 1;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE && ft_dprintf(2, TYPE_TEMPLATE_3, get_type_arg(oc, 0),
		get_type_arg(oc, 1), get_type_arg(oc, 2));
	if (read_sti_arg(vm->memory, process, args, oc) == -1)
		process->carry = 1;
	else
	{
		adr = args[1] + args[2];
		process->carry = adr == 0;
		DEBUG_R_FC && ft_dprintf(2,
			FUNC_PREFIX "sti r(%d) :(%.2hx + %.2hx = %.2hx)\n", args[0], pos,
			adr, get_restrict_address(pos, adr));
		args[0] = BSWAP_32(args[0]);
		write_in_mem_wrapper(vm, process, (uint8_t *)args,
			(t_coord){get_restrict_address(pos, adr), sizeof(*args)});
	}
	DEBUG_CARRY && ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
