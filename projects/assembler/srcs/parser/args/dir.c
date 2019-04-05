/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:45:15 by lroux             #+#    #+#             */
/*   Updated: 2019/04/04 16:16:05 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/math.h>
#include "assembler.h"
#include "lexer.h"

static t_byte	getsize(t_ins *ins)
{
	t_byte	i;

	i = -1;
	while (++i < ins->op->argcount)
		if (ins->op->argtypes[i] & T_IND)
			return (2);
	return (4);
}

static t_bool	dirlbl(t_asm *env, t_node **tokens, t_ins *ins)
{
	next(tokens);
	if (!isvalidlabel(env, tokens))
		return (false);
	ft_printf(":<L>: << to '%s' @ %#x \n", tok(tokens)->val,
			env->data.size);
	pushbytes(env, 0, getsize(ins));
	return (true);
}

t_bool			argdir(t_asm *env, t_node **tokens, t_ins *ins)
{
	if (!isvalidarg(env, tokens, ins, T_DIR))
		return (false);
	next(tokens);
	if (ins->ocp)
		*ins->ocp |= T_DIR;
	if (ins->ocp)
		*ins->ocp <<= 2;
	if (accept(tok(tokens), LBLMARK))
	{
		if (!dirlbl(env, tokens, ins))
			return (false);
	}
	else
	{
		if (!isvalidnum(env, tokens, 0))
			return (false);
		pushbytes(env, ft_strtoll(tok(tokens)->val, NULL, 0), getsize(ins));
	}
	next(tokens);
	return (true);
}
