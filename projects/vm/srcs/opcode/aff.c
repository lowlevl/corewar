/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:27:38 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/21 16:57:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

void exec_aff(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t oc;
	uint8_t ch;

	(void)op;
	oc = read_octet_code(process, vm->memory);
	if (get_type_arg(oc, 0) == T_REG)
	{
		ch = get_reg(process, read_arg(process, vm->memory, T_REG)) % 256;
		DEBUG_R_FC && ft_dprintf(2, "aff %%%d\n", ch);
		process->carry = ch == 0;
		if (ch == 0 || ch == '\n')
		{
			process_print_taunt_buffer(vm, process);
		}
		else
		{
			process->taunt_buffer[process->taunt_size] = ch;
			process->taunt_size++;
			if (process->taunt_size >= TAUNT_BUFFER_SIZE - 1)
			{
				process_print_taunt_buffer(vm, process);
			}
		}
	}
	else
		process->carry = 1;
}
