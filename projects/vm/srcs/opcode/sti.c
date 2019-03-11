/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:27:51 by glodi             #+#    #+#             */
/*   Updated: 2019/03/11 16:56:58 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

int get_type_arg(uint8_t co, uint8_t arg_number)
{
	arg_number = MAX_ARGS_NUMBER - arg_number - 1;
	if ((co & 0b11 << (arg_number * 2)) == (OC_REG << (arg_number * 2)))
		return (T_REG);
	else if ((co & 0b11 << (arg_number * 2)) == (OC_IND << (arg_number * 2)))
		return (T_IND);
	else if ((co & 0b11 << (arg_number * 2)) == (OC_DIR << (arg_number * 2)))
		return (T_DIR);
	return -1;
}

void exec_sti(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  co;
	uint8_t *pos;

	pos = (uint8_t *)get_pos_in_memory(vm->memory, process);
	pos++; // skip opcode
	// 1. Check si OCP -> Récupérer l'OCP
	if (op->has_opt)
	{
		co = *pos;
		pos++;
		ft_printf("%hhx %hhx %hhx\n", get_type_arg(co, 0), get_type_arg(co, 1),
				  get_type_arg(co, 2));
	}
	// 3. Récupérer les paramêtres en fonction de l'OCP
	// 4. Executer l'opcode
}
