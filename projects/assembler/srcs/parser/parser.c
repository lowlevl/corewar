/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:44:32 by lroux             #+#    #+#             */
/*   Updated: 2019/03/25 20:34:02 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <lift/string.h>
#include <libpf.h>

static t_bool	parselabels(t_asm *env, t_node **tokens)
{
	size_t	invalid;

	invalid = ft_strspn(tok(tokens)->val, LABEL_CHARS);
	if (tok(tokens)->val[invalid])
		return (!perr(8, env->sname, tok(tokens)->y, tok(tokens)->x + invalid,
			tok(tokens)->val[invalid],
			ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
			env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x + invalid, '^'));
	ft_printf(":<L>: Found {under}label{eoc}: '%s'.\n", tok(tokens)->val);
	shiftb(tokens, LBLMARK);
	return (true);
}

t_bool			parser(t_asm *env, t_node **tokens)
{
	int		skip;
	int		errors;

	skip = 0;
	errors = 0;
	while (tokens && *tokens)
	{
		skip = (skip != 0) ? skip - 1 : 0;
		if (accept(tok(tokens), COMMNTMARK))
			shift(tokens, NL);
		else if (accept(tok(tokens), NL))
			;
		else if (!skip && accept(tok(tokens), LITTERAL)
				&& accept(tok(&(*tokens)->next), LBLMARK))
			errors += !parselabels(env, tokens);
		else if (!skip && accept(tok(tokens), LITTERAL))
			errors += !parseinst(env, tokens);
		else if (!skip && accept(tok(tokens), CMDMARK)
				&& accept(tok(&(*tokens)->next), LITTERAL))
			errors += !parsecmd(env, &skip, tokens);
		else
			errors += !shouterror(env, tok(tokens), tokens, 6);
		next(tokens);
	}
	return (!errors);
}
