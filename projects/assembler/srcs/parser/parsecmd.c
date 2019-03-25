/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:34:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/25 20:36:41 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	parsecmd(t_asm *env, int *skip, t_node **tokens)
{
	size_t	startpos;
	size_t	endpos;

	*skip = 2;
	next(tokens);
	ft_printf(":<C>: Found {under}command{eoc}: '%s'.\n", tok(tokens)->val);
	shift(tokens, LITTERAL);
	if (accept(tok(tokens), QUOTE))
	{
		startpos = tok(tokens)->pos + 1;
		shift(tokens, QUOTE);
		shiftb(tokens, QUOTE);
		if (!*tokens || !(*tokens)->data)
			return (!perr(7, env->sname, tok(tokens)->y, tok(tokens)->x,
					ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
					env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^'));
		endpos = tok(tokens)->pos;
		ft_printf("    -> {under}value{eoc}: '%.*s'.\n",
				endpos - startpos, env->scstring + startpos);
	}
	return (true);
}

