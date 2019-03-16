/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:52:04 by lroux             #+#    #+#             */
/*   Updated: 2019/03/16 17:23:52 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include "assembler.h"
static t_bool	lextok(t_asm *env, char *tok, t_bool nolitteral);

static void		lexlitteral(t_asm *env, char *tok)
{
	size_t validlen;

	if (!*tok)
		return ;
	validlen = ft_strspn(tok, LABEL_CHARS);
	if (*(tok + validlen))
	{
		ft_printf(":ok: T_LITTERAL: '%.*s'\n", validlen, tok);
		lextok(env, tok + validlen, true);
	}
	else
		ft_printf(":ok: T_LITTERAL: '%s'\n", tok);
}

static t_bool	lextok(t_asm *env, char *tok, t_bool nolitteral)
{
	if (!tok)
		return (false);
	if (*tok == COMMAND_CHAR)
		ft_printf(":ok: T_CMDMARK\n");
	else if (*tok == COMMENT_CHAR)
		ft_printf(":ok: T_COMMENTMARK\n");
	else if (*tok == '"')
		ft_printf(":ok: T_QUOTE\n");
	else if (*tok == '\n')
		ft_printf(":ok: T_NL\n");
	else if (nolitteral)
		ft_printf(":nop: T_UNKNWN:  '%c'\n", *tok);
	else
	{
		lexlitteral(env, tok);
		return (true);
	}
	lextok(env, tok + 1, false);
	return (true);
}

void	ast(t_asm *env)
{
	char	*tok;

	tok = ft_strtok(env->sstring, "\t\v\f\r ");
	while (lextok(env, tok, false))
		tok = ft_strtok(NULL, "\t\v\f\r ");
}
