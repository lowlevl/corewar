/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:44:32 by lroux             #+#    #+#             */
/*   Updated: 2019/04/11 17:25:18 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include "lexer.h"
#include <lift/string.h>
#include <lift/char.h>
#include <libpf.h>

static t_bool	parselabels(t_asm *env)
{
	if (!isvalidlabel(env))
		return (false);
	ll_add(&env->syms, newsymref(tok(env)->val, env->data.size, 0, 0));
	shift(env, LBLMARK);
	return (true);
}

static t_bool	hasspaceafter(t_asm *env, t_tok *tok)
{
	if (ft_inset(env->scstring[tok->pos + ft_strlen(tok->val)], "\t\v\f\r "))
		return (true);
	return (false);
}

t_bool			shouterror(t_asm *env, t_tok *tok)
{
	perr(6, env->sname, tok->y, tok->x, tok->val,
			tok->ll, tok->ls, tok->x, '^');
	shiftb(env, NL);
	return (false);
}

t_bool			parser(t_asm *env)
{
	int errors;

	errors = 0;
	while (tok(env)->type != EOF)
	{
		env->skip = (env->skip != 0) ? env->skip - 1 : 0;
		if (accept(tok(env), COMMNTMARK))
			shift(env, NL);
		else if (accept(tok(env), NL))
			next(env);
		else if (!env->skip && accept(tok(env), LITTERAL)
				&& accept(env->tokens->next->data, LBLMARK)
				&& !hasspaceafter(env, tok(env)))
			errors += !parselabels(env);
		else if (!env->skip && accept(tok(env), LITTERAL))
			errors += !parseinst(env);
		else if (!env->skip && accept(tok(env), CMDMARK)
				&& accept(env->tokens->next->data, LITTERAL))
			errors += !parsecmd(env);
		else
			errors += !shouterror(env, tok(env));
	}
	return (!errors);
}
