/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:58:40 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/01 15:49:16 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

__attribute_const__ uint16_t get_restrict_address(int16_t current, int16_t plus)
{
	// if (current + plus < 0)
	// 	return (uint16_t)((current + plus % IDX_MOD + MEM_SIZE) % MEM_SIZE);
	// return (uint16_t)((current + plus % IDX_MOD) % MEM_SIZE);
	return (get_address(current, plus % IDX_MOD));
}

__attribute_const__ uint16_t get_address(int16_t current, int16_t plus)
{
	int16_t val;

	val = current + plus;
	if (val < 0)
		val += MEM_SIZE;
	val %= MEM_SIZE;
	ft_dprintf(2, "test %hd + %hd = %hd ret (%hd)\n", current, plus,
		current + plus, val);
	return (val);
}

int get_argument_all_restrict_4(
	size_t info[2], uint32_t *save, uint8_t *mem, t_process *proc)
{
	if (info[0] == T_REG)
		*save = get_reg(proc, read_arg(proc, mem, T_REG));
	else if (info[0] == T_IND)
		*save = get_indirect_restrict(info[1], read_arg(proc, mem, T_IND), mem);
	else if (info[0] == T_DIR)
		*save = read_arg(proc, mem, T_DIR_4);
	else
		return (-1);
	return (0);
}

int get_argument_all_restrict(
	size_t info[2], uint32_t *save, uint8_t *mem, t_process *proc)
{
	if (info[0] == T_REG)
		*save = get_reg(proc, read_arg(proc, mem, T_REG));
	else if (info[0] == T_IND)
		*save = get_indirect_restrict(info[1], read_arg(proc, mem, T_IND), mem);
	else if (info[0] == T_DIR)
		*save = read_arg(proc, mem, T_DIR);
	else
		return (-1);
	return (0);
}

int get_argument_all(
	size_t info[2], uint32_t *save, uint8_t *mem, t_process *proc)
{
	if (info[0] == T_REG)
		*save = get_reg(proc, read_arg(proc, mem, T_REG));
	else if (info[0] == T_IND)
		*save = get_indirect(info[1], read_arg(proc, mem, T_IND), mem);
	else if (info[0] == T_DIR)
		*save = read_arg(proc, mem, T_DIR);
	else
		return (-1);
	return (0);
}
