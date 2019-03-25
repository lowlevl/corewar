/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseinst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:59 by lroux             #+#    #+#             */
/*   Updated: 2019/03/25 20:35:42 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	argdir(t_asm *env, t_tok *tok, t_node **tokens)
{
//	next(tokens, &tok);
	ft_printf("    -> {under}type{eoc}: {blue}D{eoc} -> %s\n", tok->val);
	shift(tokens, LITTERAL);
	return (true);
}

static t_bool	parsearguments(t_asm *env, t_tok *tok, t_node **tokens)
{
	while ((tok = ll_pop(tokens, 0)))
	{
		if (accept(tok, DIRMARK))
			argdir(env, tok, tokens);
		else if (accept(tok, LITTERAL) && *tok->val == 'r')
		{
			ft_printf("    -> {under}type{eoc}: {blue}R{eoc} -> %s\n", tok->val + 1);
		}
		else
		{
			ft_printf("    -> {red}{under}error{eoc}: %s\n", tok->val);
			break ;
		}
		if (!accept((*tokens)->data, SEP))
			break ;
//		next(tokens, &tok);
	}
	return (true);
}

t_bool			parseinst(t_asm *env, t_node **tokens)
{
	ft_printf(":<I>: Found {under}instruction{eoc}: '%s'.\n", tok(tokens)->val);
	shiftb(tokens, NL);
//	return (parsearguments(env, tok, tokens));
	return (true);
}
