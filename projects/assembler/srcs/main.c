/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/03/23 17:23:25 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int ac, char **av)
{
	static t_asm	env;
	t_node			*tokens;
	t_node			*freeme;
	t_tok			*tok;

	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!(tokens = lexer(&env, av[1])))
		return (failure);
	freeme = ll_dup(tokens);
	if (!parser(&env, &tokens))
		return (failure);
//	if (!writebin(&env))
//		return (failure);
	/* Free end */
	free((void*)env.scstring);
	while ((tok = ll_pop(&freeme, 0)))
	{
		free(tok->val);
		free(tok);
	}
	return (success);
}
