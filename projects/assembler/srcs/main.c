/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/03/14 17:43:04 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	static t_asm	env;

	if (ac != 2)
		return (perr(1, av[0]));
	env.self = av[0];
	if (!getfile(av[1], &env))
		return (1); /* Free if error */
	if (!parse(&env))
		return (1); /* Free if error */
//	if (!backpatch(&env))
//		return (1);
	if (!writebin(&env))
		return (1);
	/* Free end */
	return (0);
}
