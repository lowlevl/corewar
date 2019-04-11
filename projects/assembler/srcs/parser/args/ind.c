/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:47:01 by lroux             #+#    #+#             */
/*   Updated: 2019/04/11 15:19:27 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/math.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	indlbl(t_asm *env, t_ins *ins)
{
	next(env);
	if (!isvalidlabel(env))
		return (false);
	ll_add(&env->refs,
		newsymref(tok(env)->val, env->data.size, IND_SIZE, ins->off));
	pushbytes(env, 0, IND_SIZE);
	return (true);
}

t_bool			argind(t_asm *env, t_ins *ins)
{
	if (!isvalidarg(env, ins, T_IND))
		return (false);
	if (ins->ocp)
		*ins->ocp |= IND_CODE;
	if (ins->ocp)
		*ins->ocp <<= 2;
	if (accept(tok(env), LBLMARK))
	{
		if (!indlbl(env, ins))
			return (false);
	}
	else
	{
		if (!isvalidnum(env, 0))
			return (false);
		pushbytes(env, ft_strtoll(tok(env)->val, NULL, 0), IND_SIZE);
	}
	next(env);
	return (true);
}
