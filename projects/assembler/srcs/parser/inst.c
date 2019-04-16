/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:59 by lroux             #+#    #+#             */
/*   Updated: 2019/04/11 17:32:47 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	expectedtok(t_asm *env)
{
	perr(12, env->sname, tok(env)->y, tok(env)->x,
			tok(env)->ll, tok(env)->ls, tok(env)->x, '^');
	return (false);
}

static t_bool	errors(t_asm *env, t_ins *ins, int num)
{
	if (num == 0)
		perr(9, env->sname, tok(env)->y, tok(env)->x, tok(env)->val,
				tok(env)->ll, tok(env)->ls, tok(env)->x, '^');
	else if (num == 1)
		perr(13, env->sname, tok(env)->y, tok(env)->x, ins->op->token,
				tok(env)->ll, tok(env)->ls, tok(env)->x, '^');
	else if (num == 2)
		perr(11, env->sname, tok(env)->y, tok(env)->x, ins->op->token,
				tok(env)->ll, tok(env)->ls, tok(env)->x, '^');
	shiftb(env, NL);
	return (false);
}

static t_bool	doparsearg(t_asm *env, t_ins *ins)
{
	int e;

	e = 0;
	if (accept(tok(env), NL))
		return (expectedtok(env));
	else if (ins->ac > ins->op->argcount - 1)
		return (errors(env, ins, 2));
	else if (ins->ac < ins->op->argcount && accept(tok(env), DIRMARK))
		e += !argdir(env, ins);
	else if (ins->ac < ins->op->argcount && accept(tok(env), LITTERAL)
			&& *tok(env)->val == 'r')
		e += !argreg(env, ins);
	else if (ins->ac < ins->op->argcount && (accept(tok(env), LITTERAL)
				|| accept(tok(env), LBLMARK)))
		e += !argind(env, ins);
	else
		e += !shouterror(env, tok(env));
	if (e)
		return (false);
	return (true);
}

static t_bool	parsearguments(t_asm *env, t_ins *ins)
{
	while (tok(env)->type != EOF)
	{
		++ins->ac;
		if (!doparsearg(env, ins))
			return (false);
		if (!accept(tok(env), SEP))
			break ;
		next(env);
		if (accept(tok(env), EOF))
			return (shouterror(env, tok(env)));
	}
	return (true);
}

t_bool			parseinst(t_asm *env)
{
	t_ins	ins;

	env->skip = 2;
	ins.op = g_op - 1;
	while ((++ins.op)->token && !ft_strequ(tok(env)->val, ins.op->token))
		;
	if (!ins.op->token)
		return (errors(env, &ins, 0));
	next(env);
	ins.off = env->data.size;
	pushbytes(env, ins.op->code, sizeof(t_byte));
	ins.ocp = (ins.op->ocp && !env->toolarge)
			? (env->data.code + env->data.size) : NULL;
	if (ins.ocp)
		pushbytes(env, 0, sizeof(t_byte));
	ins.ac = -1;
	if (!parsearguments(env, &ins))
		return (false);
	if (ins.ac != ins.op->argcount - 1)
		return (errors(env, &ins, 1));
	if (ins.ocp)
		*ins.ocp <<= (3 - ins.op->argcount) * 2;
	return (true);
}
