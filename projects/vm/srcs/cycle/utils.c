/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/25 09:33:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "g_op.h"
#include "g_ops.h"

inline const t_op	*get_opcode(uint8_t val)
{
	val--;
	if (val >= 0 && val < sizeof(g_op) / sizeof(*g_op))
	{
		return (g_op + val);
	}
	errno = EINVAL;
	return (NULL);
}

const t_op			*get_op(t_vm *v, t_process *p)
{
	return (get_opcode(*(uint8_t *)get_pos_in_memory(v->memory, p)));
}

const t_ops			*get_ops(const t_op *op)
{
	if (op)
		return (g_ops + op->opcode - 1);
	return (NULL);
}

static void			exec_process_in(
	t_vm *vm, t_process *process, const t_op *op, const t_ops *ops)
{
	if (process->exec_cycle != -1 && process->exec_cycle <= vm->cycle_count)
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
	if (process->exec_cycle == -1)
	{
		op = get_op(vm, process);
		ops = get_ops(op);
		if (setup_next_exec(vm, process, op, vm->cycle_count != 0))
			set_jump_to(vm, process->exec_cycle);
		else
			set_jump_to(vm, vm->cycle_count + 1);
	}
	else
		set_jump_to(vm, process->exec_cycle);
}

void				exec_process(t_vm *vm, t_process *process)
{
	const t_op	*op;
	const t_ops	*ops;

	op = get_op(vm, process);
	ops = get_ops(op);
	DEBUG_PROC
		&& ft_dprintf(2, PROC_PRE "proc id {red}#%d{eoc}\n", process->id);
	if (ops && ops->name != NULL)
	{
		return (exec_process_in(vm, process, op, ops));
	}
	DEBUG_EXE && ft_dprintf(2, EXE_PREFIX "skip\n");
	process_move_cursor(process, 1);
	set_jump_to(vm, vm->cycle_count + 1);
}
