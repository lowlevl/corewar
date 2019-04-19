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

void set_jump_to(t_vm *vm, int64_t exec_cycle)
{
	DEBUG_SET_JUMP &&ft_dprintf(2, JUMP_PRE "try(%d)\n", exec_cycle);
	if (vm->jump_to > exec_cycle && exec_cycle > 0)
		vm->jump_to = exec_cycle;
}

int setup_next_exec(t_vm *vm, t_process *process, const t_op *op, off_t off)
{
	if (process->exec_cycle == -1 && op)
	{
		process->exec_cycle = vm->cycle_count + op->duration - 1 + off;
		DEBUG_EXE &&ft_dprintf(
			2, EXE_NEXT_TEMPLATE, op->opcode, op->name, process->exec_cycle);
		return 1;
	}
	return 0;
}

__attribute__((const)) inline const t_op *get_opcode(uint8_t val)
{
	val--;
	if (val >= 0 && val < sizeof(g_op) / sizeof(*g_op))
	{
		return (g_op + val);
	}
	errno = EINVAL;
	return (NULL);
}

const t_op *get_op(t_vm *v, t_process *p)
{
	return get_opcode(*(uint8_t *)get_pos_in_memory(v->memory, p));
}

const t_ops *get_ops(const t_op *op)
{
	if (op)
		return g_ops + op->opcode - 1;
	return NULL;
}

void exec_process(t_vm *vm, t_process *process)
{
	const t_op * op;
	const t_ops *ops;

	op = get_op(vm, process);
	ops = get_ops(op);
	DEBUG_PROC &&ft_dprintf(2, PROC_PRE "proc id {red}#%d{eoc}\n", process->id);
	if (ops && ops->name != NULL)
	{
		if (process->exec_cycle != -1 && process->exec_cycle <= vm->cycle_count)
		{
			process->exec_cycle = -1;
			process_move_cursor(process, 1);
			DEBUG_EXE &&ft_dprintf(2, EXE_TEMPLATE, op->opcode, op->name,
				vm->cycle_count, get_idx_in_memory(process) - 1);
			ops->f(vm, process, op);
			DEBUG_CR_P &&ft_dprintf(2, CURSOR_TEMPLATE,
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
		return;
	}
	DEBUG_EXE &&ft_dprintf(2, EXE_PREFIX "skip\n");
	process_move_cursor(process, 1);
	set_jump_to(vm, vm->cycle_count + 1);
}

// void exec_process(t_vm *vm, t_process *process)
// {
// 	uint8_t *	pos;
// 	const t_op * op;
// 	const t_ops *ops;

// 	pos = get_pos_in_memory(vm->memory, process);
// 	op = get_opcode(*pos);
// 	DEBUG_PROC &&ft_dprintf(2, PROC_PRE "proc id {red}#%d{eoc}\n", process->id);
// 	if (op)
// 	{
// 		ops = g_ops + op->opcode - 1;
// 		if (ops->name != NULL)
// 		{
// 			setup_next_exec(vm, process, op, 0);
// 			if (process->exec_cycle <= vm->cycle_count)
// 			{
// 				process->exec_cycle = -1;
// 				process_move_cursor(process, 1);
// 				DEBUG_EXE &&ft_dprintf(2, EXE_TEMPLATE, op->opcode, op->name,
// 					vm->cycle_count, get_idx_in_memory(process) - 1);
// 				ops->f(vm, process, op);
// 				DEBUG_CR_P &&ft_dprintf(2, CURSOR_TEMPLATE,
// 					get_idx_in_memory(process),
// 					vm->memory[get_idx_in_memory(process)]);
// 				setup_next_exec_full(vm, process);
// 			}
// 			else
// 				set_jump_to(vm, process->exec_cycle);
// 			return;
// 		}
// 	}
// 	DEBUG_EXE &&ft_dprintf(2, EXE_PREFIX "skip\n");
// 	set_jump_to(vm, vm->cycle_count + 1);
// 	process_move_cursor(process, 1);
// }
