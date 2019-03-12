/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_op.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:49:03 by glodi             #+#    #+#             */
/*   Updated: 2019/03/12 14:02:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OP_H
# define G_OP_H

#include <proc.h>

const t_op    g_op[17] = {
	{"live", 1, {T_DIR}, 0x1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 0x2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 0x3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 0x4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 0x5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 0x6, 6,	"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x7, 6,"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x8, 6,"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 0x9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0xa, 25,"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 0xb, 25,"store index", 1, 1},
	{"fork", 1, {T_DIR}, 0xc, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 0xd, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0xe, 50,"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 0xf, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 0x10, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

#endif
