/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:58:40 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/25 09:48:54 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

size_t	get_restrict_address(size_t current, size_t plus)
{
	return (current + plus % IDX_MOD);
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
