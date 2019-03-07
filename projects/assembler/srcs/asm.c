/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:03:13 by lroux             #+#    #+#             */
/*   Updated: 2019/03/07 18:49:45 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <string.h>
#include <errno.h>

static int	validatefile(char *name, t_asm *env)
{
	size_t namelen;

	namelen = ft_strlen(name);
	if (namelen < 3 || !ft_strequ(&name[namelen - 2], ".s"))
		return (perr(3, name, env->self));
	env->srcname = name;
	if ((env->srcfd = open(env->srcname, O_RDONLY)) == -1)
		return (perr(4, name, strerror(errno)));
	if (read(env->srcfd, 0, 0) == -1)
		return (perr(4, name, strerror(errno)));
	return (0);
}

int			main(int ac, char **av)
{
	static t_asm	env;
	int				ret;

	if (ac != 2)
		return (perr(0, av[0]));
	env.self = av[0];
	if ((ret = validatefile(av[1], &env)) != 0)
		return (1);
	printf("Much parse, much assembly !\n");
	return (0);
}
