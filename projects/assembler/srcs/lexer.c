/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:52:04 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 19:57:53 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libpf.h>
#include <lift/string.h>
#include <lift/memory.h>
#include "lexer.h"

static const t_lexmap	g_lexmap[128] = {
	{COMMENT_CHAR, COMMNTMARK},
	{LABEL_CHAR, LBLMARK},
	{DIRECT_CHAR, DIRMARK},
	{COMMAND_CHAR, CMDMARK},
	{SEPARATOR_CHAR, SEP},
	{'"', QUOTE},
	{'\n', NL},
	{'\0', 0}
};

static t_tok	*newtok(t_asm *env, int type, char *val, size_t len)
{
	t_tok	*tok;
	size_t	pos;

	if (!(tok = ft_calloc(1, sizeof(*tok))))
		return (NULL);
	tok->type = type;
	tok->val = ft_strndup(val, len);
	pos = val - env->sstring;
	tok->y = ft_strncc(env->scstring, pos, '\n') + 1;
	tok->x = pos - ft_strncspn(env->scstring, tok->y - 1, "\n")
		+ ((tok->y - 1) ? -1 : 0) + 1;
	return (tok);
}

static void		lexlitteral(t_asm *env, t_node **toks, char *tok)
{
	size_t validlen;

	if (!*tok)
		return ;
	validlen = ft_strspn(tok, LABEL_CHARS);
	if (*(tok + validlen))
	{
		ll_add(toks, newtok(env, LITTERAL, tok, validlen));
		lextok(env, toks, tok + validlen, true);
	}
	else
		ll_add(toks, newtok(env, LITTERAL, tok, ft_strlen(tok)));
}

static t_bool	lextok(t_asm *env, t_node **toks, char *tok, t_bool nolitteral)
{
	size_t	z;

	if (!tok)
		return (false);
	z = -1;
	while (g_lexmap[++z].id)
	{
		if (*tok == g_lexmap[z].id)
		{
			ll_add(toks, newtok(env, g_lexmap[z].type, tok, 1));
			lextok(env, toks, tok + 1, false);
			return (true);
		}
	}
	if (nolitteral)
		ll_add(toks, newtok(env, UNKNOWN, tok, 1));
	else
	{
		lexlitteral(env, toks, tok);
		return (true);
	}
	lextok(env, toks, tok + 1, false);
	return (true);
}

t_bool			lexer(t_asm *env, t_node **toks, char *file)
{
	char	*tok;

	if (!getfile(env, file))
		return (false);
	tok = ft_strtok(env->sstring, "\t\v\f\r ");
	while (lextok(env, toks, tok, false))
		tok = ft_strtok(NULL, "\t\v\f\r ");
	return (true);
}
