/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:26:42 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 16:24:56 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/char.h>
#include <lift/math.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	isvalidlabel(t_asm *env, t_node **tokens)
{
	size_t	invalid;

	if (tok(tokens)->type != LITTERAL)
	{
		perr(15, env->sname, tok(tokens)->y, tok(tokens)->x,
			tok(tokens)->ll, tok(tokens)->ls,
			tok(tokens)->x, '^');
		shiftb(tokens, NL);
		return (false);
	}
	invalid = ft_strspn(tok(tokens)->val, LABEL_CHARS);
	if (tok(tokens)->val[invalid])
	{
		perr(8, env->sname, tok(tokens)->y, tok(tokens)->x + invalid,
			tok(tokens)->val[invalid], tok(tokens)->ll, tok(tokens)->ls,
			tok(tokens)->x + invalid, '^');
		shiftb(tokens, NL);
		return (false);
	}
	return (true);
}

t_bool	isvalidnum(t_asm *env, t_node **tokens, size_t start)
{
	size_t	invalid;
	char	*end;

	if (!tok(tokens)->val[start])
	{
		perr(16, env->sname, tok(tokens)->y, tok(tokens)->x + start,
			tok(tokens)->ll, tok(tokens)->ls,
			tok(tokens)->x + start, '^');
		shiftb(tokens, NL);
		return (false);
	}
	ft_strtoll(tok(tokens)->val + start, &end, 0);
	invalid = end - tok(tokens)->val;
	if (tok(tokens)->val[invalid])
	{
		perr(14, env->sname, tok(tokens)->y, tok(tokens)->x + invalid,
			tok(tokens)->val[invalid], tok(tokens)->ll, tok(tokens)->ls,
			tok(tokens)->x + invalid, '^');
		shiftb(tokens, NL);
		return (false);
	}
	return (true);
}

t_bool	isvalidarg(t_asm *env, t_node **tokens, t_op op, int *both)
{
	if (!(op.argtypes[both[0]] & both[1]))
	{
		perr(10, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
				tok(tokens)->ll, tok(tokens)->ls, tok(tokens)->x, '^');
		shiftb(tokens, NL);
		return (false);
	}
	return (true);
}
