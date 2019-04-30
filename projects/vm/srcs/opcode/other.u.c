/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:58:40 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/30 21:27:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

uint16_t	get_restrict_address(int16_t current, int16_t plus)
{
	if (current + plus < 0)
		return (uint16_t)((current + plus % IDX_MOD + MEM_SIZE) % MEM_SIZE);
	return (uint16_t)((current + plus % IDX_MOD) % MEM_SIZE);
}

uint16_t get_address(int16_t current, int16_t plus)
{
	if (current + plus < 0)
		return (uint16_t)((current + plus + MEM_SIZE) % MEM_SIZE);
	return (uint16_t)((current + plus) % MEM_SIZE);
}

int		get_argument_all_restrict_4(
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

int		get_argument_all_restrict(
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

int		get_argument_all(
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
