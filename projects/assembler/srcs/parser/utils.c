/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:28:49 by lroux             #+#    #+#             */
/*   Updated: 2019/04/11 16:50:55 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <lift/string.h>
#include <libpf.h>

void	shift(t_asm *env, int type)
{
	t_tok	*tokn;

	if (tok(env)->type == EOF)
		return ;
	while ((tokn = tok(env)))
	{
		ll_shift(&env->tokens, 1);
		if (tokn->type == type || tokn->type == EOF)
			return ;
	}
}

void	shiftb(t_asm *env, int type)
{
	t_tok	*tokn;

	if (tok(env)->type == EOF)
		return ;
	while ((tokn = tok(env)))
	{
		if (tokn->type == type || tokn->type == EOF)
			return ;
		ll_shift(&env->tokens, 1);
	}
}

void	next(t_asm *env)
{
	if (tok(env)->type != EOF)
		ll_shift(&env->tokens, 1);
}

t_tok	*tok(t_asm *env)
{
	return (env->tokens->data);
}

t_bool	accept(t_tok *tok, int type)
{
	if (tok->type == type)
		return (true);
	return (false);
}
