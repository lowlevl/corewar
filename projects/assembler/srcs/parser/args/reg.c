/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:46:23 by lroux             #+#    #+#             */
/*   Updated: 2019/03/27 15:46:33 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	argreg(t_asm *env, t_node **tokens, t_op op, int *i)
{
	if (!(op.argtypes[*i] & T_REG))
	{
		perr(10, env->sname, tok(tokens)->y, tok(tokens)->x, op.token,
				ft_strcspn(env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, "\n"),
				env->scstring + (tok(tokens)->pos - tok(tokens)->x) + 1, tok(tokens)->x, '^');
		shiftb(tokens, NL);
		return (false);
	}
	ft_printf("    -> {under}type{eoc}: {blue}R{eoc} -> %s\n",
			tok(tokens)->val + 1);
	next(tokens);
	return (true);
}

