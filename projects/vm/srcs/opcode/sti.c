/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:27:51 by glodi             #+#    #+#             */
/*   Updated: 2019/03/12 14:38:06 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static void copy_to(uint32_t *copy_to, uint32_t val)
{
	*copy_to = val;
}

static int read_sti_arg(
	uint32_t *args, uint8_t **pos, t_process *process, uint8_t oc)
{
	uint8_t type_arg;

	if (get_type_arg(oc, 0) == T_REG)
		args[0] = get_reg(process, read_arg(pos, T_REG));
	else
		return -1;

	type_arg = get_type_arg(oc, 1);
	if (type_arg == T_REG)
		args[1] = get_reg(process, read_arg(pos, T_REG));
	else if (type_arg == T_IND)
		args[1] = read_arg(pos, T_IND);
	else
		return -1;

	type_arg = get_type_arg(oc, 2);
	if (type_arg == T_REG)
		args[2] = get_reg(process, read_arg(pos, T_REG));
	else if (type_arg == T_IND)
		args[2] = read_arg(pos, T_IND);
	else
		return -1;
	return 0;
}

void exec_sti(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  oc;
	uint8_t *pos;
	uint32_t args[3];
	uint16_t adr;
	uint8_t *save_pos;

	(void)op;
	process->exec_cycle = -1;
	ft_bzero(args, sizeof(args));
	pos = (uint8_t *)get_pos_in_memory(vm->memory, process);
	save_pos = pos;
	pos++;
	oc = read_octet_code(&pos);
	if (read_sti_arg(args, &pos, process, oc) == -1 ||
		(adr = args[1] + args[2]) == 0)
	{
		process->carry = 1;
	}
	else
	{
		copy_to((uint32_t *)save_pos + adr % IDX_MOD, args[0]);
	}
	process->cursor_pos = pos - save_pos;
}
