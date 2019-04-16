/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:46:23 by lroux             #+#    #+#             */
/*   Updated: 2019/04/08 18:59:24 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/math.h>
#include "assembler.h"
#include "lexer.h"

t_bool	argreg(t_asm *env, t_node **tokens, t_ins *ins)
{
	if (!isvalidarg(env, tokens, ins, T_REG)
			|| !isvalidnum(env, tokens, 1))
		return (false);
	if (ins->ocp)
		*ins->ocp |= REG_CODE;
	if (ins->ocp)
		*ins->ocp <<= 2;
	pushbytes(env, ft_strtoll(tok(tokens)->val + 1, NULL, 0), REG_SIZE);
	next(tokens);
	return (true);
}
