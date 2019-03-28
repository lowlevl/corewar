/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:28:49 by lroux             #+#    #+#             */
/*   Updated: 2019/03/28 17:56:12 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <lift/string.h>
#include <libpf.h>

void	shift(t_node **tokens, int type)
{
	t_tok	*tok;

	while ((tok = ll_pop(tokens, 0)) && tok->type != type)
		;
}

void	shiftb(t_node **tokens, int type)
{
	t_tok	*tok;

	while ((tok = ll_pop(tokens, 0)) && tok->type != type)
		;
	ll_add(tokens, tok);
	ll_shift(tokens, -1);
}

t_tok	*next(t_node **tokens)
{
	return (ll_pop(tokens, 0));
}

t_tok	*tok(t_node **tokens)
{
	return ((*tokens)->data);
}

t_bool	accept(t_tok *tok, int type)
{
	if (tok->type == type)
		return (true);
	return (false);
}
