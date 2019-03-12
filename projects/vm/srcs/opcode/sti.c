/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:27:51 by glodi             #+#    #+#             */
/*   Updated: 2019/03/12 10:32:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

int get_type_arg(uint8_t co, uint8_t arg_number)
{
	arg_number = (MAX_ARGS_NUMBER - arg_number - 1) * 2;
	if ((co & 0b11 << arg_number) == (OC_REG << arg_number))
		return (T_REG);
	else if ((co & 0b11 << arg_number) == (OC_IND << arg_number))
		return (T_IND);
	else if ((co & 0b11 << arg_number) == (OC_DIR << arg_number))
		return (T_DIR);
	return -1;
}

int read_arg(uint8_t **pos, int type)
{
	uint16_t val;

	if (type == T_REG)
	{
		val = **pos;
		*pos = *pos + 1;
		return val;
	}
	else if (type == T_IND)
	{
		val = bswap_16(**(uint16_t **)pos);
		*pos = *pos + sizeof(val);
		return val;
	}
	else if (type == T_DIR)
	{
		val = bswap_16(**(uint16_t **)pos);
		*pos = *pos + sizeof(val);
		return val;
	}
	return -1;
}

void exec_sti(t_vm *vm, t_process *process, const t_op *op)
{
	uint8_t  co;
	uint8_t *pos;

	pos = (uint8_t *)get_pos_in_memory(vm->memory, process);
	pos++; // skip opcode
	// 1. Check si OCP -> Récupérer l'OCP
	co = *pos;
	pos++;
	ft_printf("%hhx %hhx %hhx\n", get_type_arg(co, 0), get_type_arg(co, 1),
				get_type_arg(co, 2));
	ft_printf("%x %x %x %x\n", read_arg(&pos, get_type_arg(co, 0)),
				read_arg(&pos, get_type_arg(co, 1)),
				read_arg(&pos, get_type_arg(co, 2)), *pos);
	// 3. Récupérer les paramêtres en fonction de l'OCP
	// 4. Executer l'opcode
}
