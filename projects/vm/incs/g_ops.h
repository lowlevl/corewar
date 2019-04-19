/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ops.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:01:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 14:51:34 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OPS_H
# define G_OPS_H

# include "opcode.h"
# include "struct.h"

const t_ops g_ops[17] = {
	{ "live", exec_live },
	{ "ld", exec_ld },
	{ "st", exec_st },
	{ "add", exec_add },
	{ "sub", exec_sub },
	{ "and", exec_and },
	{ "or", exec_or },
	{ "xor", exec_xor },
	{ "zjump", exec_zjump },
	{ "ldi", exec_ldi },
	{ "sti", exec_sti },
	{ "fork", exec_fork },
	{ "lld", exec_lld },
	{ "lldi", exec_lldi },
	{ "lfork", exec_lfork },
	{ "aff", exec_aff },
	{NULL, NULL},
};

#endif
