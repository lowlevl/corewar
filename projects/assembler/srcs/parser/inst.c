/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:59 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 17:16:01 by lroux            ###   ########.fr       */
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

static t_bool	errors(t_asm *env, t_node **tokens, t_op op, int num)
{
	if (num == 0)
		perr(9, env->sname, tok(tokens)->y, tok(tokens)->x, tok(tokens)->val,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	else if (num == 1)
		perr(13, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	else if (num == 2)
		perr(11, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
	shiftb(tokens, NL);
	return (false);
}

static t_bool	doparsearg(t_asm *env, t_node **tokens, t_op op, int *i)
{
	int e;

	e = 0;
	if (accept(tok(tokens), NL))
		return (expectedtok(env, tokens));
	else if (*i > op.argcount - 1)
		return (errors(env, tokens, op, 2));
	else if (*i < op.argcount && accept(tok(tokens), DIRMARK))
		e += !argdir(env, tokens, op, i);
	else if (*i < op.argcount && accept(tok(tokens), LITTERAL)
			&& *tok(tokens)->val == 'r')
		e += !argreg(env, tokens, op, i);
	else if (*i < op.argcount && (accept(tok(tokens), LITTERAL)
				|| accept(tok(tokens), LBLMARK)))
		e += !argind(env, tokens, op, i);
	else
		++e;
	if (e)
		return (false);
	return (true);
}

static t_bool	parsearguments(t_asm *env, t_node **tokens, t_op op, int *i)
{
	while (tokens && *tokens)
	{
		++(*i);
		if (!doparsearg(env, tokens, op, i))
			return (false);
		if (!accept(tok(tokens), SEP))
			break ;
		next(tokens);
	}
	return (true);
}

t_bool			parseinst(t_asm *env, t_node **tokens)
{
	int		i;
	t_op	op;

	env->skip = 2;
	i = -1;
	while (g_op[++i].token)
		if (ft_strequ(tok(tokens)->val, g_op[i].token))
			break ;
	op = g_op[i];
	if (!op.token)
		return (errors(env, tokens, op, 0));
	next(tokens);
	ft_printf(":<I>: Found {under}instruction{eoc}: '%s'.\n", op.token);
	i = -1;
	if (!parsearguments(env, tokens, op, &i))
		return (false);
	if (i != op.argcount - 1)
		return (errors(env, tokens, op, 1));
	/* Push to code array */
	return (true);
}
