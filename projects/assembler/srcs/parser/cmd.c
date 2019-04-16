/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:34:07 by lroux             #+#    #+#             */
/*   Updated: 2019/04/11 17:20:57 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/math.h>
#include <lift/string.h>
#include <lift/memory.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	cmdquoted(t_asm *env, t_tok *ntok)
{
	size_t	startpos;
	size_t	endpos;
	t_tok	*ctok;

	ctok = tok(env);
	startpos = ctok->pos + 1;
	shift(env, QUOTE);
	shiftb(env, QUOTE);
	if (tok(env)->type == EOF)
	{
		perr(7, env->sname, ctok->y, ctok->x, ctok->ll, ctok->ls, ctok->x, '^');
		return (false);
	}
	endpos = tok(env)->pos;
	if (ft_strequ(ntok->val, "name"))
		ft_memcpy(env->data.head.name, env->scstring + startpos,
				ft_min(endpos - startpos, PROG_NAME_LENGTH));
	else if (ft_strequ(ntok->val, "comment"))
		ft_memcpy(env->data.head.comment, env->scstring + startpos,
				ft_min(endpos - startpos, COMMENT_LENGTH));
	else
		perr(18, env->sname, ntok->y, ntok->x, ntok->val,
				ntok->ll, ntok->ls, ntok->x, '^');
	next(env);
	return (true);
}

static t_bool	cmdnum(t_asm *env, t_tok *ntok)
{
	if (!isvalidnum(env, 0))
		return (false);
	if (ft_strequ(ntok->val, "byte"))
		pushbytes(env, ft_strtoll(tok(env)->val, NULL, 0), 1);
	else
		perr(18, env->sname, ntok->y, ntok->x, ntok->val,
				ntok->ll, ntok->ls, ntok->x, '^');
	next(env);
	return (true);
}

static t_bool	cmdnull(t_asm *env, t_tok *ntok)
{
	perr(18, env->sname, ntok->y, ntok->x, ntok->val,
			ntok->ll, ntok->ls, ntok->x, '^');
	return (true);
}

t_bool			parsecmd(t_asm *env)
{
	t_tok *ntok;

	env->skip = 2;
	next(env);
	ntok = tok(env);
	next(env);
	if (accept(tok(env), QUOTE))
		return (cmdquoted(env, ntok));
	else if (accept(tok(env), LITTERAL))
		return (cmdnum(env, ntok));
	else
		return (cmdnull(env, ntok));
}
