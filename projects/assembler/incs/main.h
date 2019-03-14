/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:54:47 by lroux             #+#    #+#             */
/*   Updated: 2019/03/14 18:39:07 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <errno.h>
# include <lift/list.h>
# include "op.h"

# define MAX_FILEOUT (sizeof(t_head) + CHAMP_MAX_SIZE)

typedef struct	s_binary {
	t_head	head;
	t_byte	code[CHAMP_MAX_SIZE];
	size_t	codesize;
}				t_binary;

typedef struct	s_symbol {
	char	*name;
	void	*value;
}				t_symbol;

typedef struct	s_asm {
	char	*self;

	char	*sname;
	char	**sarray;

	size_t	linecount;
	size_t	y;

	t_node		*symbols;
	t_node		*references;
	t_binary	data;
}				t_asm;

/*
** Error management
*/
int				perr(int e, ...);

/*
** Utilities
*/
t_bool			getfile(char *name, t_asm *env);
char			*gnline(t_asm *env);
char			*gcline(t_asm *env);

/*
** Parser
*/
t_bool			parse(t_asm *env);

int				writebin(t_asm *env);

#endif
