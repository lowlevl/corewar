/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:44:32 by lroux             #+#    #+#             */
/*   Updated: 2019/03/23 19:16:09 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <lift/string.h>
#include <libpf.h>

static void		parselabels(t_asm *env, t_tok *tok, t_node **tokens)
{
	ft_printf(":<L>: Found {under}label{eoc}: '%s'.\n", tok->val);
	shift(tokens, LBLMARK);
}

static void		parseinst(t_asm *env, int *skip, t_tok *tok, t_node **tokens)
{
	*skip = 2;
	ft_printf(":<I>: Found {under}instruction{eoc}: '%s'.\n", tok->val);
	while ((tok = ll_pop(tokens, 0)))
	{
		if (accept(tok, NL) || accept(tok, COMMNTMARK) || accept(tok, UNKNOWN))
		{
			ll_add(tokens, tok);
			ll_shift(tokens, -1);
			break ;
		}
		ft_printf("    -> {under}argument{eoc}: %s\n", tok->val);
	}
	*skip = 0;
}

static int		parsecmd(t_asm *env, int *skip, t_tok *tok, t_node **tokens)
{
	size_t	startpos;
	size_t	endpos;

	*skip = 2;
	shiftb(tokens, LITTERAL);
	ft_printf(":<C>: Found {under}command{eoc}: '%s'.\n",
			((t_tok*)(*tokens)->data)->val);
	shift(tokens, LITTERAL);
	tok = (*tokens)->data;
	if (accept((*tokens)->data, QUOTE))
	{
		startpos = ((t_tok*)(*tokens)->data)->pos + 1;
		shift(tokens, QUOTE);
		shiftb(tokens, QUOTE);
		if (!*tokens || !(*tokens)->data)
			return (!perr(7, env->sname, tok->y, tok->x,
					ft_strcspn(env->scstring + (tok->pos - tok->x) + 1, "\n"),
					env->scstring + (tok->pos - tok->x) + 1, tok->x, '^'));
		endpos = ((t_tok*)(*tokens)->data)->pos;
		shift(tokens, QUOTE);
		ft_printf("    -> {under}value{eoc}: '%.*s'.\n",
				endpos - startpos, env->scstring + startpos);
	}
	return (true);
}

t_bool			parser(t_asm *env, t_node **tokens)
{
	int		skip;
	t_tok	*tok;

	skip = 0;
	while ((tok = ll_pop(tokens, 0)))
	{
		skip = (skip != 0) ? skip - 1 : 0;
		if (accept(tok, COMMNTMARK))
			shift(tokens, NL);
		else if (accept(tok, NL))
			;
		else if (!skip && accept(tok, LITTERAL)
				&& accept((*tokens)->data, LBLMARK))
			parselabels(env, tok, tokens);
		else if (!skip && accept(tok, LITTERAL))
			parseinst(env, &skip, tok, tokens);
		else if (!skip && accept(tok, CMDMARK)
				&& accept((*tokens)->data, LITTERAL))
			parsecmd(env, &skip, tok, tokens);
		else
			shouterror(env, tok, tokens, 6);
	}
	return (true);
}
