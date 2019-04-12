/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:54:47 by lroux             #+#    #+#             */
/*   Updated: 2019/03/28 18:29:46 by lroux            ###   ########.fr       */
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

	int			skip;

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

	char	*ls;
	size_t	ll;
}				t_tok;

/*
** Error management
*/
int				perr(int e, ...);

/*
** Lexer & Parser
*/
t_node			*lexer(t_asm *env, char *name);

t_bool			parser(t_asm *env, t_node **tokens);
t_bool			parsecmd(t_asm *env, t_node **tokens);
t_bool			parseinst(t_asm *env, t_node **tokens);
t_bool			argind(t_asm *env, t_node **tokens, t_op op, int *i);
t_bool			argreg(t_asm *env, t_node **tokens, t_op op, int *i);
t_bool			argdir(t_asm *env, t_node **tokens, t_op op, int *i);
t_bool			isvalidarg(t_asm *env, t_node **tokens, t_op op, int *both);
t_bool			isvalidnum(t_asm *env, t_node **tokens, size_t start);
t_bool			isvalidlabel(t_asm *env, t_node **tokens);

/*
** Parsing utils
*/
void			shift(t_node **tokens, int type);
void			shiftb(t_node **tokens, int type);
t_tok			*next(t_node **tokens);
t_tok			*tok(t_node **tokens);
t_bool			accept(t_tok *tok, int type);

/*
** Binary writing
*/
t_bool			writebin(t_asm *env);

#endif
