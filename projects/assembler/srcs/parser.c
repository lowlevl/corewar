/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:44:32 by lroux             #+#    #+#             */
/*   Updated: 2019/03/23 16:01:25 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <libpf.h>

static void		shift(t_node **tokens, int type)
{
	t_bool	loop;
	t_tok	*tok;

	loop = true;
	while (loop && (tok = ll_pop(tokens, 0)))
	{
		if (tok->type == type)
			loop = false;
		free(tok->val);
		free(tok);
	}
}

static void		shiftb(t_node **tokens, int type)
{
	t_tok	*tok;

	while ((tok = ll_pop(tokens, 0)))
	{
		if (tok->type == type)
			break ;
		free(tok->val);
		free(tok);
	}
	ll_add(tokens, tok);
	ll_shift(tokens, -1);
}

static t_bool	accept(t_tok *tok, int type)
{
	if (tok->type == type)
		return (true);
	return (false);
}

static void		parselabels(t_asm *env, t_tok *tok, t_node **tokens)
{
	ft_printf(":<>: Found {under}label{eoc}: '%s'.\n", tok->val);
	shift(tokens, LBLMARK);
}

static void		parseinst(t_asm *env, int *skip, t_tok *tok, t_node **tokens)
{
	*skip = 2;
	ft_printf(":<>: Found {under}instruction{eoc}: '%s'.\n", tok->val);
	while ((tok = ll_pop(tokens, 0)))
	{
		if (accept(tok, COMMNTMARK))
			shift(tokens, NL);
		if (accept(tok, NL) || accept(tok, COMMNTMARK) || accept(tok, UNKNOWN))
			break ;
		ft_printf("    -> {under}argument{eoc}: %s\n", tok->val);
	}
	*skip = 0;
}

static void		parsecmd(t_asm *env, int *skip, t_tok *tok, t_node **tokens)
{
	size_t	startpos;
	size_t	endpos;

	*skip = 2;
	shiftb(tokens, LITTERAL);
	ft_printf(":<>: Found {under}command{eoc}: '%s'.\n", ((t_tok*)(*tokens)->data)->val);
	shift(tokens, LITTERAL);
	if (!accept((*tokens)->data, QUOTE))
		return ;
	startpos = ((t_tok*)(*tokens)->data)->pos + 1;
	shift(tokens, QUOTE);
	shiftb(tokens, QUOTE);
	if (!*tokens || !(*tokens)->data)
		return ;
	endpos = ((t_tok*)(*tokens)->data)->pos;
	shift(tokens, QUOTE);
	ft_printf("    -> {under}value{eoc}: '%.*s'.\n",
			endpos - startpos, env->scstring + startpos);
}

static void		shouterror(t_asm *env, t_tok *tok, t_node **tokens)
{
	shift(tokens, NL);
	ft_printf(":<>: {red}(%d){eoc} -> {bold}%s{eoc}"
			"\n    @{blue}%d:%d{eoc}\n", tok->type, tok->val, tok->y, tok->x);
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
		else if (!skip && accept(tok, LITTERAL) && accept((*tokens)->data, LBLMARK))
			parselabels(env, tok, tokens);
		else if (!skip && accept(tok, LITTERAL))
			parseinst(env, &skip, tok, tokens);
		else if (!skip && accept(tok, CMDMARK) && accept((*tokens)->data, LITTERAL))
			parsecmd(env, &skip, tok, tokens);
		else
			shouterror(env, tok, tokens);
		free(tok->val);
		free(tok);
	}
	return (true);
}
