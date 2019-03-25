/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseinst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:59 by lroux             #+#    #+#             */
/*   Updated: 2019/03/25 22:02:31 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	argdir(t_asm *env, t_node **tokens)
{
	size_t invalid;

	next(tokens);
	ft_printf("    -> {under}type{eoc}: {blue}D{eoc} -> %s\n",
			tok(tokens)->val);
	if (accept(tok(tokens), LBLMARK))
	{
		next(tokens);
		invalid = ft_strspn(tok(tokens)->val, LABEL_CHARS);
		if (tok(tokens)->val[invalid])
			return (!perr(8, env->sname, tok(tokens)->y, tok(tokens)->x + invalid,
						tok(tokens)->val[invalid],
						ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
						env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x + invalid, '^'));
		/* Case :label */
	}
	else
		/* Case %dir */
		;
	next(tokens);
	return (true);
}

static t_bool	argreg(t_asm *env, t_node **tokens)
{
	ft_printf("    -> {under}type{eoc}: {blue}R{eoc} -> %s\n",
			tok(tokens)->val + 1);
	next(tokens);
	return (true);
}

static t_bool	argind(t_asm *env, t_node **tokens)
{
	size_t invalid;

	ft_printf("    -> {under}type{eoc}: {blue}I{eoc} -> %s\n",
			tok(tokens)->val);
	if (accept(tok(tokens), LBLMARK))
	{
		next(tokens);
		invalid = ft_strspn(tok(tokens)->val, LABEL_CHARS);
		if (tok(tokens)->val[invalid])
			return (!perr(8, env->sname, tok(tokens)->y, tok(tokens)->x + invalid,
						tok(tokens)->val[invalid],
						ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
						env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x + invalid, '^'));
		/* Case :label */
	}
	else
		/* Case ind */
		;
	next(tokens);
	return (true);
}

static t_bool	parsearguments(t_asm *env, t_node **tokens, t_op op)
{
	while (tokens && *tokens)
	{
		if (accept(tok(tokens), DIRMARK))
			argdir(env, tokens);
		else if (accept(tok(tokens), LITTERAL) && *tok(tokens)->val == 'r')
			argreg(env, tokens);
		else if (accept(tok(tokens), LITTERAL) || accept(tok(tokens), LBLMARK))
			argind(env, tokens);
		else
		{
			ft_printf("    -> {red}{under}error{eoc}: %s\n",
				tok(tokens)->val);
			return (false);
		}
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

	i = -1;
	while (g_op[++i].token)
		if (ft_strequ(tok(tokens)->val, g_op[i].token))
			break ;
	op = g_op[i];
	if (!op.token)
	{
		perr(9, env->sname, tok(tokens)->y, tok(tokens)->x, tok(tokens)->val,
			ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
			env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^');
		shiftb(tokens, NL);
		return (false);
	}
	ft_printf(":<I>: Found {under}instruction{eoc}: '%s'.\n", tok(tokens)->val);
	next(tokens);
	if (!parsearguments(env, tokens, op))
		return (false);
	/* Push to code array */
	return (true);
}
