/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:28:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/25 09:28:38 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"

void				set_jump_to(t_vm *vm, int64_t exec_cycle)
{
	DEBUG_SET_JUMP && ft_dprintf(2, JUMP_PRE "try(%d)\n", exec_cycle);
	if (vm->jump_to > exec_cycle && exec_cycle > 0)
		vm->jump_to = exec_cycle;
}

int					setup_next_exec(
		t_vm *vm, t_process *process, const t_op *op, off_t off)
{
	if (process->exec_cycle == -1 && op)
	{
		process->exec_cycle = vm->cycle_count + op->duration - 1 + off;
		DEBUG_EXE && ft_dprintf(
			2, EXE_NEXT_TEMPLATE, op->opcode, op->name, process->exec_cycle);
		return (1);
	}
	return (0);
}
