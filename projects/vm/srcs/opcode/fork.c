/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:57:48 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/03 09:29:53 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

void exec_fork(t_vm *vm, t_process *process, const t_op *op)
{
	int16_t  adr;
	uint16_t pos;

	(void)op;
	pos = process->cursor_pos - 1;
	adr = read_arg(process, vm->memory, T_DIR);
	DEBUG_R_FC &&ft_dprintf(2, FUNC_P "fork (%hd + %hd = %hu(%hx))\n", pos, adr,
		get_restrict_address(pos, adr), get_restrict_address(pos, adr));
	copy_process(vm, process, get_restrict_address(pos, adr));
}
