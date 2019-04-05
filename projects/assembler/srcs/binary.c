/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:55:18 by lroux             #+#    #+#             */
/*   Updated: 2019/04/04 16:17:46 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <stdlib.h>
#include "assembler.h"

t_op	g_op[17] =
{
	{"live", 0x01,
		1, {T_DIR},
		false},
	{"ld", 0x02,
		2, {T_DIR | T_IND, T_REG},
		true},
	{"st", 0x03,
		2, {T_REG, T_IND | T_REG},
		true},
	{"add", 0x04,
		3, {T_REG, T_REG, T_REG},
		true},
	{"sub", 0x05,
		3, {T_REG, T_REG, T_REG},
		true},
	{"and", 0x06,
		3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		true},
	{"or", 0x07,
		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		true},
	{"xor", 0x08,
		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		true},
	{"zjmp", 0x09,
		1, {T_DIR},
		false},
	{"ldi", 0x0a,
		3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		true},
	{"sti", 0x0b,
		3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		true},
	{"fork", 0x0c,
		1, {T_DIR},
		false},
	{"lld", 0x0d,
		2, {T_DIR | T_IND, T_REG},
		true},
	{"lldi", 0x0e,
		3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		true},
	{"lfork", 0x0f,
		1, {T_DIR},
		false},
	{"aff", 0x10,
		1, {T_REG},
		true},
	{NULL, 0, 0, {0}, false}
};

void			pushbytes(t_asm *env, t_u32 data, size_t size)
{
	if (env->data.size + size > sizeof(env->data.code))
		env->toolarge = true;
	else
	{
		if (size == 1)
			*((t_u8*)env->data.code + env->data.size) = (t_u8)data;
		else if (size == 2)
			*((t_u16*)env->data.code + env->data.size) = (t_u16)data;
		else
			*((t_u32*)env->data.code + env->data.size) = (t_u32)data;
	}
	env->data.size += size;
}

t_bool	writebin(t_asm *env)
{
	if (env->toolarge)
		return (!perr(17, env->sname,
				env->data.size, CHAMP_MAX_SIZE));
	ft_printf(":<(O)>: {green}Building binary{eoc} %dB/%dB :D\n", env->data.size, CHAMP_MAX_SIZE);
	return (true);
}
