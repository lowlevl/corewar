/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:29:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/03 09:30:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static int	read_args_st(
	uint8_t *mem, t_process *process, uint32_t *args, uint8_t oc)
{
	uint8_t	type_arg;

	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(process, mem, T_REG));
	else
		return (-1);
	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_REG)
		args[1] = read_arg(process, mem, T_REG);
	else if (type_arg == T_IND)
		args[1] = read_arg(process, mem, T_IND);
	else
		return (-1);
	return (0);
}

static void	exec_st_in(
	t_process *process, uint32_t args[2], size_t info[2], t_vm *vm)
{
	process->carry = args[0] == 0;
	if (get_type_arg(info[0], 1) == T_REG)
	{
		DEBUG_R_FC && ft_dprintf(
			2, FUNC_P "st %%%d r%d\n", args[0], args[1]);
		write_in_registre(process, args[1], args[0]);
	}
	else if (get_type_arg(info[0], 1) == T_IND)
	{
		DEBUG_R_FC && ft_dprintf(2,
			FUNC_P "st %%%d :(%.2hx + %.2hx = %.2hx)\n", args[0], info[1],
			args[1], get_restrict_address(info[1], args[1]));
		args[0] = BSWAP_32(args[0]);
		write_in_mem_wrapper(vm, process, (uint8_t *)args,
			(t_coord){get_restrict_address(info[1], args[1]), sizeof(*args)});
	}
}

void		exec_st(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t		oc;
	size_t		pos;
	uint32_t	args[2];

	(void)op;
	pos = get_idx_in_memory(process) - 1;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE && ft_dprintf(
		2, TYPE_TEMPLATE_2, get_type_arg(oc, 0), get_type_arg(oc, 1));
	if (read_args_st(vm->memory, process, args, oc) == 0)
	{
		exec_st_in(process, args, (size_t[2]){oc, pos}, vm);
	}
	else
	{
		DEBUG_R_FC&&ft_dprintf(2, FUNC_P "st" BAD_ARG);
		process->carry = 1;
	}
	DEBUG_CARRY && ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
