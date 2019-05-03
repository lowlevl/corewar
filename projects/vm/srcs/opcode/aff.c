/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:27:38 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/03 09:30:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"
#include "socket.h"
#include "proc.h"

static void	print(t_vm *vm, t_process *process)
{
	process->taunt_buffer[process->taunt_size] = 0;
	send_taunt(&vm->socket, process);
	process_print_taunt_buffer(vm, process);
}

void		exec_aff(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t	oc;
	uint8_t	ch;

	(void)op;
	oc = read_octet_code(process, vm->memory);
	DEBUG_TYPE && ft_dprintf(2, TYPE_TEMPLATE_1, get_type_arg(oc, 0));
	if (get_type_arg(oc, 0) == T_REG)
	{
		ch = get_reg(process, read_arg(process, vm->memory, T_REG)) % 256;
		DEBUG_R_FC && ft_dprintf(2, FUNC_P "aff %%%d\n", ch);
		process->carry = ch == 0;
		if (ch == 0 || ch == '\n')
			print(vm, process);
		else
		{
			process->taunt_buffer[process->taunt_size] = ch;
			process->taunt_size++;
			if (process->taunt_size >= TAUNT_BUFFER_SIZE - 1)
				print(vm, process);
		}
	}
	else
	{
		DEBUG_R_FC && ft_dprintf(2, FUNC_P "aff" BAD_ARG);
		process->carry = 1;
	}
	DEBUG_CARRY && ft_dprintf(2, CARRY_TEMPLATE, process->carry);
}
