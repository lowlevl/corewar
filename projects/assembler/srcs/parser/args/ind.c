/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:47:01 by lroux             #+#    #+#             */
/*   Updated: 2019/04/04 16:17:00 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/math.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	indlbl(t_asm *env, t_node **tokens)
{
	next(tokens);
	if (!isvalidlabel(env, tokens))
		return (false);
	ft_printf(":<L>: << to '%s' @ %#x \n", tok(tokens)->val,
			env->data.size);
	pushbytes(env, 0, IND_SIZE);
	return (true);
}

t_bool			argind(t_asm *env, t_node **tokens, t_ins *ins)
{
	if (!isvalidarg(env, tokens, ins, T_IND))
		return (false);
	if (ins->ocp)
		*ins->ocp |= T_IND;
	if (ins->ocp)
		*ins->ocp <<= 2;
	if (accept(tok(tokens), LBLMARK))
	{
		if (!indlbl(env, tokens))
			return (false);
	}
	else
	{
		if (!isvalidnum(env, tokens, 0))
			return (false);
		pushbytes(env, ft_strtoll(tok(tokens)->val, NULL, 0), IND_SIZE);
	}
	next(tokens);
	return (true);
}
