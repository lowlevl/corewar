/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:54:47 by lroux             #+#    #+#             */
/*   Updated: 2019/03/23 17:57:10 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include <errno.h>
# include <lift/list.h>
# include "op.h"

# define MAX_FILEOUT (sizeof(t_head) + CHAMP_MAX_SIZE)

typedef struct __attribute__((__packed__))	s_binary {
	t_head	head;
	t_byte	code[CHAMP_MAX_SIZE];
	size_t	codesize;
}				t_binary;

typedef struct	s_symbol {
	char	*name;
	void	*value;
}				t_symbol;

typedef struct	s_asm {
	char		*self;

	char		*sname;
	char		*sstring;
	const char	*scstring;

	t_node		*symbols;
	t_node		*references;
	t_binary	data;
}				t_asm;

typedef struct	s_tok {
	int		type;
	char	*val;

	size_t	x;
	size_t	y;
	size_t	pos;
}				t_tok;

/*
** Error management
*/
int				perr(int e, ...);

/*
** Lexer & Parser
*/
char			*getfile(t_asm *env, char *name);
t_node			*lexer(t_asm *env, char *name);

t_bool			parser(t_asm *env, t_node **tokens);
void			shift(t_node **tokens, int type);
void			shiftb(t_node **tokens, int type);
t_bool			accept(t_tok *tok, int type);
void			shouterror(t_asm *env, t_tok *tok, t_node **tokens, int err);

/*
** Binary writing
*/
int				writebin(t_asm *env);

#endif
