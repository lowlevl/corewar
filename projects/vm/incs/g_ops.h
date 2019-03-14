/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ops.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:01:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 11:53:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OPS_H
# define G_OPS_H

# include "opcode.h"
# include "struct.h"

const t_ops g_ops[17] = {
	{ "live", exec_live }, // 0
	{NULL, NULL}, // 1
	{NULL, NULL}, // 2
	{NULL, NULL}, // 3
	{NULL, NULL}, // 4
	{ "and", exec_and }, // 5
	{NULL, NULL}, // 6
	{NULL, NULL}, // 7
	{NULL, NULL}, // 8
	{NULL, NULL}, // 9
	{ "sti", exec_sti }, // 10
	{NULL, NULL}, // 11
	{NULL, NULL}, // 12
	{NULL, NULL}, // 13
	{NULL, NULL}, // 14
	{NULL, NULL}, // 15
	{NULL, NULL}, // 16
};

#endif // !G_OPS_H
