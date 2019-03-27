/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:47:01 by lroux             #+#    #+#             */
/*   Updated: 2019/03/27 15:47:10 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	argind(t_asm *env, t_node **tokens, t_op op, int *i)
{
	size_t invalid;

	if (!(op.argtypes[*i] & T_IND))
	{
		perr(10, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
				ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
				env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^');
		shiftb(tokens, NL);
		return (false);
	}
	ft_printf("    -> {under}type{eoc}: {blue}I{eoc} -> %s\n",
			tok(tokens)->val);
	if (accept(tok(tokens), LBLMARK))
	{
		next(tokens);
		invalid = ft_strspn(tok(tokens)->val, LABEL_CHARS);
		if (tok(tokens)->val[invalid])
		{
			perr(8, env->sname, tok(tokens)->y, tok(tokens)->x + invalid,
						tok(tokens)->val[invalid],
						ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
						env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x + invalid, '^');
			shiftb(tokens, NL);
			return (false);
		}
		/* Case :label */
	}
	else
		/* Case ind */
		;
	next(tokens);
	return (true);
}
