/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:47:01 by lroux             #+#    #+#             */
/*   Updated: 2019/04/08 18:59:04 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/math.h>
#include "assembler.h"
#include "lexer.h"

static t_bool	indlbl(t_asm *env, t_node **tokens, t_ins *ins)
{
	next(tokens);
	if (!isvalidlabel(env, tokens))
		return (false);
	ll_add(&env->refs,
		newsymref(tok(tokens)->val, env->data.size, IND_SIZE, ins->off));
	pushbytes(env, 0, IND_SIZE);
	return (true);
}

t_bool			argind(t_asm *env, t_node **tokens, t_ins *ins)
{
	if (!isvalidarg(env, tokens, ins, T_IND))
		return (false);
	if (ins->ocp)
		*ins->ocp |= IND_CODE;
	if (ins->ocp)
		*ins->ocp <<= 2;
	if (accept(tok(tokens), LBLMARK))
	{
		if (!indlbl(env, tokens, ins))
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
