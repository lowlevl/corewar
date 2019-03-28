/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:34:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/27 16:48:09 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	parsecmd(t_asm *env, t_node **tokens)
{
	size_t	startpos;
	size_t	endpos;
	t_tok	*ctok;

	env->skip = 2;
	next(tokens);
	ft_printf(":<C>: Found {under}command{eoc}: '%s'.\n", tok(tokens)->val);
	next(tokens);
	if (accept(tok(tokens), QUOTE))
	{
		ctok = tok(tokens);
		startpos = ctok->pos + 1;
		shift(tokens, QUOTE);
		shiftb(tokens, QUOTE);
		if (!*tokens || !tok(tokens))
			return (!perr(7, env->sname, ctok->y, ctok->x,
					ctok->ll, ctok->ls, ctok->x, '^'));
		endpos = tok(tokens)->pos;
		ft_printf("    -> {under}value{eoc}: '%.*s'.\n",
				endpos - startpos, env->scstring + startpos);
		next(tokens);
	}
	return (true);
}
