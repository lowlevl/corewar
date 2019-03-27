/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:44:32 by lroux             #+#    #+#             */
/*   Updated: 2019/03/27 15:49:02 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <lift/string.h>
#include <lift/char.h>
#include <libpf.h>

static t_bool	parselabels(t_asm *env, t_node **tokens)
{
	size_t	invalid;

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
	ft_printf(":<L>: Found {under}label{eoc}: '%s'.\n", tok(tokens)->val);
	shift(tokens, LBLMARK);
	return (true);
}

static t_bool	hasspaceafter(t_asm *env, t_tok *tok)
{
	if (ft_inset(env->scstring[tok->pos + ft_strlen(tok->val)], "\t\v\f\r "))
		return (true);
	return (false);
}

t_bool			parser(t_asm *env, t_node **tokens)
{
	int		errors;

	errors = 0;
	while (tokens && *tokens)
	{
		env->skip = (env->skip != 0) ? env->skip - 1 : 0;
		if (accept(tok(tokens), COMMNTMARK))
			shift(tokens, NL);
		else if (accept(tok(tokens), NL))
			next(tokens);
		else if (!env->skip && accept(tok(tokens), LITTERAL)
				&& accept(tok(&(*tokens)->next), LBLMARK)
				&& !hasspaceafter(env, tok(tokens)))
			errors += !parselabels(env, tokens);
		else if (!env->skip && accept(tok(tokens), LITTERAL))
			errors += !parseinst(env, tokens);
		else if (!env->skip && accept(tok(tokens), CMDMARK)
				&& accept(tok(&(*tokens)->next), LITTERAL))
			errors += !parsecmd(env, tokens);
		else
			errors += !shouterror(env, tok(tokens), tokens, 6);
	}
	return (!errors);
}
