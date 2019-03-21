/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 19:53:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

#include <libpf.h>

int	main(int ac, char **av)
{
	static t_asm	env;
	static t_node	*toks;
	t_tok			*tok;

	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!lexer(&env, &toks, av[1]))
		return (failure);
	while ((tok = ll_pop(&toks, 0)))
		ft_printf(":tok: (%d) -> '%-12s' @ %d:%d\n",
						tok->type, tok->val, tok->y, tok->x);
//	if (!writebin(&env))
//		return (1);
	/* Free end */
	return (success);
}
