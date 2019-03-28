/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:47:01 by lroux             #+#    #+#             */
/*   Updated: 2019/03/28 18:36:49 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	argind(t_asm *env, t_node **tokens, t_op op, int *i)
{
	if (!isvalidarg(env, tokens, op, (int[2]){*i, T_IND}))
		return (false);
	ft_printf("    -> {under}type{eoc}: {blue}I{eoc} -> %s\n",
			tok(tokens)->val);
	if (accept(tok(tokens), LBLMARK))
	{
		next(tokens);
		if (!isvalidlabel(env, tokens))
			return (false);
		/* Case :label */
	}
	else
	{
		/* Case ind */
		if (!isvalidnum(env, tokens, 0))
			return (false);
	}
	next(tokens);
	return (true);
}
