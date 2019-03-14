/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:01:02 by lroux             #+#    #+#             */
/*   Updated: 2019/03/14 18:41:19 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <lift/string.h>
#include <lift/memory.h>
#include <lift/char.h>
#include "main.h"

char	*gnline(t_asm *env)
{
	return (ft_strdup(env->sarray[env->y++]));
}

char	*gcline(t_asm *env)
{
	return (env->sarray[env->y - 1]);
}

t_bool	getfile(char *name, t_asm *env)
{
	ssize_t	filelen;
	size_t	namelen;
	char	*content;
	int		fd;

	namelen = ft_strlen(name);
	if (namelen < 3 || !ft_strequ(&name[namelen - 2], ".s"))
		return (!perr(4, name, env->self));
	env->sname = name;
	if ((fd = open(env->sname, O_RDONLY)) == -1)
		return (!perr(3, name, strerror(errno)));
	if ((filelen = lseek(fd, 0, SEEK_END)) < 1 || lseek(fd, 0, SEEK_SET) != 0)
		return (!perr(5, name));
	if (!(content = ft_calloc(filelen + 1, sizeof(*content))))
		return (false);
	if (read(fd, content, filelen) != filelen)
		return (!perr(6, name, strerror(errno)));
	close(fd);
	if (!(env->sarray =
			ft_calloc(ft_strcc(content, '\n') + 1, sizeof(*env->sarray))))
		return (false);
	while ((env->sarray[env->linecount++] = ft_strsep(&content, "\n")))
		;
	return (true);
}

