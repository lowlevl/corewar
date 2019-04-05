/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/04/05 14:02:25 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include <string.h>

int	cleanup(int r, t_asm *env, t_node **freeme)
{
	t_tok	*tok;

	free((void*)env->scstring);
	free(strerror(0));
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
	t_node	*tokens;
	t_node	*freeme;

	freeme = 0;
	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!(tokens = lexer(&env, av[1])))
		return (cleanup(failure, &env, &freeme));
	freeme = ll_dup(tokens);
	if (!parser(&env, &tokens))
		return (cleanup(failure, &env, &freeme));
	if (!writebin(&env))
		return (cleanup(failure, &env, &freeme));
	return (cleanup(success, &env, &freeme));
}
