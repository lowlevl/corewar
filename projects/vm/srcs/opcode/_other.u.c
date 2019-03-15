/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _other.u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:58:40 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/15 14:08:48 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

size_t get_restrict_address(size_t current, size_t plus)
{
	return current + plus % IDX_MOD;
}
