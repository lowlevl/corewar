/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usagestr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:03:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/07 17:06:10 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

const char	*g_usagestr =                                                      \
"Usage: %s <input.s>\n"                                                        \
"\n"                                                                           \
"  This program is intended to compile special arch `corewar-bytecode` from\n" \
"  pseudo-assembler.\n"                                                        \
"  It will output bytecode to the file <%%.cor>.\n";
