/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:45:15 by lroux             #+#    #+#             */
/*   Updated: 2019/04/11 15:18:26 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/math.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	dirlbl(t_asm *env, t_ins *ins)
{
	next(env);
	if (!isvalidlabel(env))
		return (false);
	ll_add(&env->refs,
		newsymref(tok(env)->val, env->data.size, ins->op->ds, ins->off));
	pushbytes(env, 0, ins->op->ds);
	return (true);
}

t_bool			argdir(t_asm *env, t_ins *ins)
{
	if (!isvalidarg(env, ins, T_DIR))
		return (false);
	next(env);
	if (ins->ocp)
		*ins->ocp |= DIR_CODE;
	if (ins->ocp)
		*ins->ocp <<= 2;
	if (accept(tok(env), LBLMARK))
	{
		if (!dirlbl(env, ins))
			return (false);
	}
	else
	{
		if (!isvalidnum(env, 0))
			return (false);
		pushbytes(env, ft_strtoll(tok(env)->val, NULL, 0), ins->op->ds);
	}
	next(env);
	return (true);
}
