/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/03/21 21:42:12 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int ac, char **av)
{
	static t_asm	env;
	t_node			*tokens;
	t_tok			*tok;

	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!(tokens = lexer(&env, av[1])))
		return (failure);
	if (!parser(&env, &tokens))
		return (failure);
//	if (!writebin(&env))
//		return (1);
	/* Free end */
	free((void*)env.scstring);
	env.scstring = NULL;
	while ((tok = ll_pop(&tokens, 0)))
	{
		free(tok->val);
		free(tok);
	}
	return (success);
}
