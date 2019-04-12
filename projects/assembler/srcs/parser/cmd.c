/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:34:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 17:14:26 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/math.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	cmdquoted(t_asm *env, t_node **tokens)
{
	size_t	startpos;
	size_t	endpos;
	t_tok	*ctok;

	ctok = tok(tokens);
	startpos = ctok->pos + 1;
	shift(tokens, QUOTE);
	shiftb(tokens, QUOTE);
	if (!*tokens || !tok(tokens))
	{
		perr(7, env->sname, ctok->y, ctok->x, ctok->ll, ctok->ls, ctok->x, '^');
		return (false);
	}
	endpos = tok(tokens)->pos;
	ft_printf("    -> {under}value{eoc}: '%.*s'.\n",
			endpos - startpos, env->scstring + startpos);
	next(tokens);
	return (true);
}

static t_bool	cmdnum(t_asm *env, t_node **tokens)
{
	if (!isvalidnum(env, tokens, 0))
		return (false);
	ft_printf("    -> {under}value{eoc}: '%d'.\n",
			(int)ft_strtoll(tok(tokens)->val, NULL, 0));
	next(tokens);
	return (true);
}

static t_bool	cmdnull(t_asm *env)
{
	(void)env;
	ft_printf("    -> {under}value{eoc}: '(null)'.\n");
	return (true);
}

t_bool			parsecmd(t_asm *env, t_node **tokens)
{
	env->skip = 2;
	next(tokens);
	ft_printf(":<C>: Found {under}command{eoc}: '%s'.\n", tok(tokens)->val);
	next(tokens);
	if (accept(tok(tokens), QUOTE))
		return (cmdquoted(env, tokens));
	else if (accept(tok(tokens), LITTERAL))
		return (cmdnum(env, tokens));
	else
		return (cmdnull(env));
}
