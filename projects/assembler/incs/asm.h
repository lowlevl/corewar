/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:54:47 by lroux             #+#    #+#             */
/*   Updated: 2019/03/07 18:11:11 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <fcntl.h>
# include <libpf.h>
# include <lift/types.h>
# include <lift/string.h>

# include "error.h"

/*
** The correct usage for the assembler:
*/
const char	*g_usagestr;

typedef struct {
	char	*self;

	char	*srcname;
	int		srcfd;
}			t_asm;

#endif
