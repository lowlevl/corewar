/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:01:02 by lroux             #+#    #+#             */
/*   Updated: 2019/03/23 18:49:40 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <lift/string.h>
#include <lift/memory.h>
#include <lift/char.h>
#include "assembler.h"

char	*getfile(t_asm *env, char *name)
{
	ssize_t	filelen;
	size_t	namelen;
	char	*content;
	int		fd;

	namelen = ft_strlen(name);
	if (namelen < 3 || !ft_strequ(&name[namelen - 2], ".s"))
		return ((void*)(long)!perr(3, name, env->self));
	env->sname = name;
	if ((fd = open(env->sname, O_RDONLY)) == -1)
		return ((void*)(long)!perr(2, name, strerror(errno)));
	if ((filelen = lseek(fd, 0, SEEK_END)) < 1 || lseek(fd, 0, SEEK_SET) != 0)
		return ((void*)(long)!perr(4, name));
	if (!(content = ft_calloc(filelen + 1, sizeof(*content))))
		return (NULL);
	if (read(fd, content, filelen) != filelen)
		return ((void*)(long)!perr(5, name, strerror(errno)));
	close(fd);
	env->scstring = ft_strrep(ft_strndup(content, filelen), '\t', ' ');
	return (content);
}
