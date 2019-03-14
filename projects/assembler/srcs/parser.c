/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:00:12 by lroux             #+#    #+#             */
/*   Updated: 2019/03/14 18:42:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lift/string.h>
#include <lift/char.h>
#include <libpf.h>
#include "main.h"

static t_bool	parseop(t_asm *env, char *line, char *op, char *params)
{
	t_op	inst;
	size_t	i;

	i = -1;
	while (g_op[++i].token)
		if (ft_strequ(g_op[i].token, op))
			break ;
	inst = g_op[i];
	if (!inst.token)
		return (!perr(7, env->sname, env->y, op - line, op, gcline(env), op - line + 1, '^'));

	ft_printf("%s + %s\n", op, params);
	
	return (true);
}

static t_bool	parseline(t_asm *env, char *line)
{
	char	*s;
	char	*token;

	s = line;
	while (ft_isspace(*s))
		++s;
	if (!(token = ft_strsep(&s, SPACE_CHARS)))
		return (false);
	if (token[0] == COMMAND_CHAR)
		return true;
	else if (token[ft_strlen(token) - 1] == LABEL_CHAR)
		return true;
	else
		return (parseop(env, line, token, s));
}

t_bool			parse(t_asm *env)
{
	char	*line;

	while ((line = gnline(env)))
	{
		ft_strrep(line, COMMENT_CHAR, '\0');
		if (!*line)
			continue ;
		if (!parseline(env, line))
			return (false);
		/* Free *line */
	}
	return (true);
}
