/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ops.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:01:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 15:40:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OPS_H
# define G_OPS_H

# include "opcode.h"
# include "struct.h"

const t_ops g_ops[17] = {
	{ "live", exec_live }, // 0x1
	{NULL, NULL}, // 0x2
	{NULL, NULL}, // 0x3
	{NULL, NULL}, // 0x4
	{NULL, NULL}, // 0x5
	{ "and", exec_and }, // 0x6
	{NULL, NULL}, // 0x7
	{NULL, NULL}, // 0x8
	{ "zjump", exec_zjump }, // 0x9
	{NULL, NULL}, // 0xa
	{ "sti", exec_sti }, // 0xb
	{NULL, NULL}, // 0xc
	{NULL, NULL}, // 0xd
	{NULL, NULL}, // 0xe
	{NULL, NULL}, // 0xf
	{ "aff", exec_aff }, // 0x10
	{NULL, NULL}, // 0x00
};

#endif // !G_OPS_H
