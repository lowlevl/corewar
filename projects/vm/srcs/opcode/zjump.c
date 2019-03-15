/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:49:37 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/15 09:38:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

void exec_zjump(t_vm *vm, t_process *process, const t_op *op)
{
	uint16_t move_to;
	uint16_t pos;

	(void)op;
	pos = get_idx_in_memory(process) - 1;
	move_to = read_arg(process, vm->memory, T_DIR);
	ft_printf("%hx %hx %hx\n", pos, move_to, pos + move_to % MEM_SIZE);
	if (process->carry == 1)
	{
		process_set_cursor_pos(process, pos + move_to % MEM_SIZE);
	}
}
