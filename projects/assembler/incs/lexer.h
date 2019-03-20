/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:42:29 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 20:01:38 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "assembler.h"

typedef struct	s_lexmap {
	char	id;
	int		type;
}				t_lexmap;

enum {
	CMDMARK,
	COMMNTMARK,
	LBLMARK,
	DIRMARK,
	QUOTE,
	SEP,
	NL,
	UNKNOWN,
	LITTERAL
};

static t_bool	lextok(t_asm *env, t_node **toks, char *tok, t_bool nolitteral);

#endif
