/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/04/09 20:46:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lift/memory.h>
#include <lift/string.h>
#include "assembler.h"
#include "lexer.h"
#include <string.h>

int	cleanup(int r, t_asm *env, t_node **freeme)
{
	t_tok	*tok;

	free(env->oname);
	free((void*)env->scstring);
	free(strerror(0));
	while ((tok = ll_pop(&env->syms, 0)))
		free(tok);
	while ((tok = ll_pop(&env->refs, 0)))
		free(tok);
	while ((tok = ll_pop(&env->tokens, 0)))
		;
	while ((tok = ll_pop(freeme, 0)))
	{
		free(tok->val);
		free(tok);
	}
	return (r);
}

int	main(int ac, char **av)
{
	static t_asm	env;
	t_node			*freeme;

	freeme = 0;
	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!(env.tokens = lexer(&env, av[1]))
			|| !(env.oname = ft_calloc(ft_strlen(av[1]) + 3, sizeof(char))))
		return (cleanup(failure, &env, &freeme));
	freeme = ll_dup(env.tokens);
	if (tok(&env.tokens->prev)->type != NL)
		return (cleanup(failure, &env, &freeme));
	if (!parser(&env, &env.tokens))
		return (cleanup(failure, &env, &freeme));
	if (!writebin(&env))
		return (cleanup(failure, &env, &freeme));
	return (cleanup(success, &env, &freeme));
}
