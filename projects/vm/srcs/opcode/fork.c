/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:57:48 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/01 11:05:46 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

void	exec_fork(t_vm *vm, t_process *process, const t_op *op)
{
	int16_t	adr;
	uint16_t	pos;

	(void)op;
	pos = process->cursor_pos - 1;
	adr = read_arg(process, vm->memory, T_DIR);
	DEBUG_R_FC && ft_dprintf(2, FUNC_PREFIX "fork (%x + %x = %hx)\n", pos, adr,
			(pos + adr) % IDX_MOD);
	copy_process(vm, process, pos + adr % IDX_MOD);
}
