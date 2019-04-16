/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 18:31:09 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "g_op.h"
#include "g_ops.h"

void		exec_process(t_vm *vm, t_process *process)
{
	uint8_t		*pos;
	const t_op	*op;
	const t_ops	*ops;

	pos = get_pos_in_memory(vm->memory, process);
	op = get_opcode(*pos);
	if (op)
	{
		ops = g_ops + op->opcode - 1;
		if (ops->name != NULL)
		{
			if (process->exec_cycle == -1)
			{
				process->exec_cycle = vm->cycle_count + op->duration - 1;
				DEBUG_EXE && ft_dprintf(2, EXE_NEXT_TEMPLATE, op->opcode,
					op->name, process->exec_cycle);
			}
			if (process->exec_cycle <= vm->cycle_count)
			{
				process->exec_cycle = -1;
				process_move_cursor(process, 1);
				DEBUG_EXE && ft_dprintf(2, EXE_TEMPLATE, op->opcode, op->name,
					vm->cycle_count, get_idx_in_memory(process) - 1);
				ops->f(vm, process, op);
				DEBUG_CR_P && ft_dprintf(2, CURSOR_TEMPLATE,
					get_idx_in_memory(process),
					vm->memory[get_idx_in_memory(process)]);
			}
		}
		else
			process_move_cursor(process, 1);
	}
	else
		process_move_cursor(process, 1);
}

const t_op	*get_opcode(uint8_t val)
{
	val--;
	if (val >= 0 && val < sizeof(g_op) / sizeof(*g_op))
	{
		return (g_op + val);
	}
	errno = EINVAL;
	return (NULL);
}
