/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 09:49:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "g_op.h"
#include "g_ops.h"
#include "cycle.h"

void exec_process(t_vm *vm, t_process *process)
{
	uint8_t *   pos;
	const t_op *op;
	const t_ops *ops;

	pos = get_pos_in_memory(vm->memory, process);
	op = get_opcode(*pos);
	if (!op)
		ft_printf("NOPE\n");
	ft_printf("Exec process %p %#x (%s)\n", pos - vm->memory, op->opcode,
			  op->name);
	ops = g_ops + op->opcode - 1;
	if (ops->name != NULL)
	{
		if (process->exec_cycle == -1)
			process->exec_cycle = vm->cycle_count + op->duration;
		if (process->exec_cycle == vm->cycle_count)
			ops->f(vm, process, op);
	}
}

const t_op *get_opcode(uint8_t val)
{
	val--;
	if (val >= 0 && val < sizeof(g_op) / sizeof(*g_op))
	{
		return g_op + val;
	}
	errno = EINVAL;
	return NULL;
}
