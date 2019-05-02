/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:26:42 by lroux             #+#    #+#             */
/*   Updated: 2019/05/02 13:46:51 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/char.h>
#include <lift/math.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	isvalidlabel(t_asm *env)
{
	size_t	invalid;

	if (tok(env)->type != LITTERAL)
	{
		perr(15, env->sname, tok(env)->y, tok(env)->x,
			tok(env)->ll, tok(env)->ls,
			tok(env)->x, '^');
		shiftb(env, NL);
		return (false);
	}
	invalid = ft_strspn(tok(env)->val, LABEL_CHARS);
	if (tok(env)->val[invalid])
	{
		perr(8, env->sname, tok(env)->y, tok(env)->x + invalid,
			tok(env)->val[invalid], tok(env)->ll, tok(env)->ls,
			tok(env)->x + invalid, '^');
		shiftb(env, NL);
		return (false);
	}
	return (true);
}

t_bool	isvalidnum(t_asm *env, size_t start)
{
	size_t	invalid;
	char	*end;

	if (tok(env)->type == EOFTOK)
		return (shouterror(env, tok(env)));
	if (!tok(env)->val[start])
	{
		perr(16, env->sname, tok(env)->y, tok(env)->x + start,
			tok(env)->ll, tok(env)->ls,
			tok(env)->x + start, '^');
		shiftb(env, NL);
		return (false);
	}
	ft_strtoll(tok(env)->val + start, &end, 0);
	invalid = end - tok(env)->val;
	if (tok(env)->val[invalid])
	{
		perr(14, env->sname, tok(env)->y, tok(env)->x + invalid,
			tok(env)->val[invalid], tok(env)->ll, tok(env)->ls,
			tok(env)->x + invalid, '^');
		shiftb(env, NL);
		return (false);
	}
	return (true);
}

t_bool	isvalidarg(t_asm *env, t_ins *ins, int type)
{
	if (!(ins->op->argtypes[ins->ac] & type))
	{
		perr(10, env->sname, tok(env)->y, tok(env)->x, ins->op->token,
				tok(env)->ll, tok(env)->ls, tok(env)->x, '^');
		shiftb(env, NL);
		return (false);
	}
	return (true);
}
