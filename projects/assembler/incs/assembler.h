/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:54:47 by lroux             #+#    #+#             */
/*   Updated: 2019/04/10 16:45:36 by lroux            ###   ########.fr       */
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
	size_t	size;
}				t_binary;

typedef struct	s_symref {
	char	*name;
	size_t	data;
	size_t	size;
	size_t	off;
}				t_symref;

typedef struct	s_asm {
	char		*self;

	char		*sname;
	char		*sstring;
	const char	*scstring;

	char		*oname;

	int			skip;
	t_bool		toolarge;
	t_bool		isbinary;

	t_node		*tokens;
	t_node		*syms;
	t_node		*refs;
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

typedef struct	s_ins {
	t_op	*op;
	t_byte	ac;

	t_byte	*ocp;
	size_t	off;
}				t_ins;

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
t_bool			argind(t_asm *env, t_node **tokens, t_ins *ins);
t_bool			argreg(t_asm *env, t_node **tokens, t_ins *ins);
t_bool			argdir(t_asm *env, t_node **tokens, t_ins *ins);
t_bool			isvalidarg(t_asm *env, t_node **tokens, t_ins *ins, int type);
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
t_symref		*newsymref(char *name, size_t data, size_t size, size_t off);
void			pushbytes(t_asm *env, t_u32 data, size_t size);
t_bool			writebin(t_asm *env);

#endif
