/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:42:29 by lroux             #+#    #+#             */
/*   Updated: 2019/05/20 13:55:27 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "assembler.h"

# define LITTERALCHARS	LABEL_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ-"

typedef struct	s_lexmap {
	char	id;
	int		type;
}				t_lexmap;

# define CMDMARK	1
# define COMMNTMARK	2
# define LBLMARK	3
# define DIRMARK	4
# define QUOTE		5
# define SEP		6
# define NL			7
# define EOFTOK		8
# define UNKNOWN	9
# define LITTERAL	10

# ifdef INSIDE

static t_bool	lextok(t_asm *env, t_node **toks, char *tok, t_bool nolitteral);

# endif
#endif
