/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:57:48 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 17:02:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

void exec_lfork(t_vm *vm, t_process *process, const t_op *op)
{
	uint16_t adr;
	size_t   pos;

	(void)op;
	pos = get_idx_in_memory(process) - 1;
	adr = read_arg(process, vm->memory, T_DIR);
	copy_process(vm, process, pos + adr);
}
