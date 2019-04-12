/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:46:23 by lroux             #+#    #+#             */
/*   Updated: 2019/03/28 18:36:39 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"

t_bool	argreg(t_asm *env, t_node **tokens, t_op op, int *i)
{
	if (!isvalidarg(env, tokens, op, (int[2]){*i, T_REG})
			|| !isvalidnum(env, tokens, 1))
		return (false);
	ft_printf("    -> {under}type{eoc}: {blue}R{eoc} -> %s\n",
			tok(tokens)->val + 1);
	next(tokens);
	return (true);
}
