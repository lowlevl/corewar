/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:55:18 by lroux             #+#    #+#             */
/*   Updated: 2019/04/16 11:41:01 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/memory.h>
#include <lift/string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "assembler.h"

t_op	g_op[17] =
{
	{"live", 0x01,
		1, {T_DIR},
		false, 4},
	{"ld", 0x02,
		2, {T_DIR | T_IND, T_REG},
		true, 4},
	{"st", 0x03,
		2, {T_REG, T_IND | T_REG},
		true, 0},
	{"add", 0x04,
		3, {T_REG, T_REG, T_REG},
		true, 0},
	{"sub", 0x05,
		3, {T_REG, T_REG, T_REG},
		true, 0},
	{"and", 0x06,
		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		true, 4},
	{"or", 0x07,
		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		true, 4},
	{"xor", 0x08,
		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		true, 4},
	{"zjmp", 0x09,
		1, {T_DIR},
		false, 2},
	{"ldi", 0x0a,
		3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		true, 2},
	{"sti", 0x0b,
		3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		true, 2},
	{"fork", 0x0c,
		1, {T_DIR},
		false, 2},
	{"lld", 0x0d,
		2, {T_DIR | T_IND, T_REG},
		true, 4},
	{"lldi", 0x0e,
		3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		true, 2},
	{"lfork", 0x0f,
		1, {T_DIR},
		false, 2},
	{"aff", 0x10,
		1, {T_REG},
		true, 0},
	{NULL, 0, 0, {0}, false, 0}
};

void		pushbytes(t_asm *env, t_u32 data, size_t size)
{
	if (env->data.size + size > sizeof(env->data.code))
		env->toolarge = true;
	else
	{
		if (size == 1)
			*((t_u8*)&env->data.code[env->data.size]) = (t_u8)data;
		else if (size == 2)
			*((t_u16*)&env->data.code[env->data.size]) = ft_bswp16(data);
		else
			*((t_u32*)&env->data.code[env->data.size]) = ft_bswp32(data);
	}
	env->data.size += size;
}

t_symref	*newsymref(char *name, size_t data, size_t size, size_t off)
{
	t_symref	*sr;

	if (!(sr = ft_calloc(1, sizeof(*sr))))
		return (NULL);
	sr->name = name;
	sr->data = data;
	sr->size = size;
	sr->off = off;
	return (sr);
}

t_symref	*getsym(t_asm *env, char *name)
{
	t_node	*sr;
	t_bool	ok;

	ok = false;
	sr = env->syms;
	while (true)
	{
		if (ft_strequ(name, ((t_symref*)sr->data)->name))
		{
			ok = true;
			break ;
		}
		sr = sr->next;
		if (sr == env->syms)
			break ;
	}
	if (!ok)
		return (NULL);
	return (sr->data);
}

t_bool		resolverefs(t_asm *env)
{
	t_symref	*sym;
	t_symref	*ref;
	int			errs;

	errs = 0;
	while ((ref = ll_pop(&env->refs, 0)))
	{
		if (!(sym = getsym(env, ref->name)))
			errs += perr(19, env->sname, ref->name);
		else
		{
			if (ref->size == 2)
				*((t_u16*)&env->data.code[ref->data]) = ft_bswp16(sym->data
						- ref->off);
			else
				*((t_u32*)&env->data.code[ref->data]) = ft_bswp32(sym->data
						- ref->off);
		}
		free(ref);
	}
	return (!errs);
}

t_bool		writebin(t_asm *env)
{
	int		fd;
	size_t	wl;

	if (env->toolarge)
		return (!perr(17, env->sname, env->data.size, CHAMP_MAX_SIZE));
	if (!resolverefs(env))
		return (false);
	if (ft_strlen(env->data.head.name) == 0)
		ft_strcpy(env->data.head.name, "<No name>");
	if (ft_strlen(env->data.head.comment) == 0)
		ft_strcpy(env->data.head.comment, "<No comment>");
	env->data.head.magic = ft_bswp32(COREWAR_EXEC_MAGIC);
	env->data.head.size = ft_bswp32(env->data.size);
	ft_strcpy(env->oname, env->sname);
	ft_strcpy(env->oname + ft_strlen(env->sname) - 2, ".cor");
	if ((fd = open(env->oname,
			O_WRONLY | O_CREAT | O_TRUNC | O_EXLOCK, 0664)) == -1)
		return (!perr(5, env->oname, strerror(errno)));
	wl = write(fd, &env->data, sizeof(env->data.head) + env->data.size);
	close(fd);
	if (wl != sizeof(env->data.head) + env->data.size)
		return
		(!perr(21, env->oname, wl, sizeof(env->data.head) + env->data.size));
	return (perr(20, env->sname, env->oname, env->data.size));
}
