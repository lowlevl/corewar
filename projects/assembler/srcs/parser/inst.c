/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:59 by lroux             #+#    #+#             */
/*   Updated: 2019/03/27 15:47:17 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	parsearguments(t_asm *env, t_node **tokens, t_op op, int *i)
{
	while (tokens && *tokens)
	{
		++(*i);
		if (accept(tok(tokens), NL))
		{
			perr(12, env->sname, tok(tokens)->y, tok(tokens)->x,
					ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
					env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^');
			return (false);
		}
		else if (*i > op.argcount - 1)
		{
			perr(11, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
					ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
					env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^');
			shiftb(tokens, NL);
			return (false);
		}
		else if (*i < op.argcount && accept(tok(tokens), DIRMARK))
		{
			if (!argdir(env, tokens, op, i))
				return (false);
		}
		else if (*i < op.argcount && accept(tok(tokens), LITTERAL) && *tok(tokens)->val == 'r')
		{
			if (!argreg(env, tokens, op, i))
				return (false);
		}
		else if (*i < op.argcount && (accept(tok(tokens), LITTERAL) || accept(tok(tokens), LBLMARK)))
		{
			if (!argind(env, tokens, op, i))
				return (false);
		}
		else
		{
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

	env->skip = 2;
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
	next(tokens);
	ft_printf(":<I>: Found {under}instruction{eoc}: '%s'.\n", op.token);
	i = -1;
	if (!parsearguments(env, tokens, op, &i))
		return (false);
	if (i != op.argcount - 1)
	{
		perr(13, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
			ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
			env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^');
		shiftb(tokens, NL);
		return (false);
	}
	/* Push to code array */
	return (true);
}
