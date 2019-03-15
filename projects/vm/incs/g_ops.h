/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ops.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:01:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/15 10:26:29 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OPS_H
# define G_OPS_H

# include "opcode.h"
# include "struct.h"

const t_ops g_ops[17] = {
	{ "live", exec_live }, // 0x1
	{ "ld", exec_ld }, // 0x2
	{NULL, NULL}, // 0x3
	{ "add", exec_add }, // 0x4
	{ "sub", exec_sub }, // 0x5
	{ "and", exec_and }, // 0x6
	{ "or", exec_or }, // 0x7
	{ "xor", exec_xor }, // 0x8
	{ "zjump", exec_zjump }, // 0x9
	{NULL, NULL}, // 0xa
	{ "sti", exec_sti }, // 0xb
	{ "fork", exec_fork }, // 0xc
	{NULL, NULL}, // 0xd
	{NULL, NULL}, // 0xe
	{ "lfork", exec_lfork }, // 0xf
	{ "aff", exec_aff }, // 0x10
	{NULL, NULL}, // 0x00
};

#endif // !G_OPS_H
