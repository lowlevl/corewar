/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:59 by lroux             #+#    #+#             */
/*   Updated: 2019/04/04 15:14:32 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	expectedtok(t_asm *env, t_node **tokens)
{
	perr(12, env->sname, tok(tokens)->y, tok(tokens)->x,
			tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	return (false);
}

static t_bool	errors(t_asm *env, t_node **tokens, t_ins *ins, int num)
{
	if (num == 0)
		perr(9, env->sname, tok(tokens)->y, tok(tokens)->x, tok(tokens)->val,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	else if (num == 1)
		perr(13, env->sname, tok(tokens)->y, tok(tokens)->x, ins->op->token,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	else if (num == 2)
		perr(11, env->sname, tok(tokens)->y, tok(tokens)->x, ins->op->token,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	shiftb(tokens, NL);
	return (false);
}

static t_bool	doparsearg(t_asm *env, t_node **tokens, t_ins *ins)
{
	int e;

	e = 0;
	if (accept(tok(tokens), NL))
		return (expectedtok(env, tokens));
	else if (ins->ac > ins->op->argcount - 1)
		return (errors(env, tokens, ins, 2));
	else if (ins->ac < ins->op->argcount && accept(tok(tokens), DIRMARK))
		e += !argdir(env, tokens, ins);
	else if (ins->ac < ins->op->argcount && accept(tok(tokens), LITTERAL)
			&& *tok(tokens)->val == 'r')
		e += !argreg(env, tokens, ins);
	else if (ins->ac < ins->op->argcount && (accept(tok(tokens), LITTERAL)
				|| accept(tok(tokens), LBLMARK)))
		e += !argind(env, tokens, ins);
	else
		++e;
	if (e)
		return (false);
	return (true);
}

static t_bool	parsearguments(t_asm *env, t_node **tokens, t_ins *ins)
{
	while (tokens && *tokens)
	{
		++ins->ac;
		if (!doparsearg(env, tokens, ins))
			return (false);
		if (!accept(tok(tokens), SEP))
			break ;
		next(tokens);
	}
	return (true);
}

t_bool			parseinst(t_asm *env, t_node **tokens)
{
	t_ins	ins;

	env->skip = 2;
	ins.op = g_op - 1;
	while ((++ins.op)->token && !ft_strequ(tok(tokens)->val, ins.op->token))
		;
	if (!ins.op->token)
		return (errors(env, tokens, &ins, 0));
	next(tokens);
	ins.off = env->data.size;
	pushbytes(env, ins.op->code, sizeof(t_byte));
	ins.ocp = (ins.op->ocp && !env->toolarge)
			? (env->data.code + env->data.size) : NULL;
	if (ins.ocp)
		pushbytes(env, 0, sizeof(t_byte));
	ins.ac = -1;
	if (!parsearguments(env, tokens, &ins))
		return (false);
	if (ins.ac != ins.op->argcount - 1)
		return (errors(env, tokens, &ins, 1));
	if (ins.ocp)
		*ins.ocp <<= (3 - ins.op->argcount) * 2;
	return (true);
}
