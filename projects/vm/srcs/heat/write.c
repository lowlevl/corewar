/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:34:08 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/01 10:12:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heat_map.h"

void assign_player_to_area(t_vm *vm, int player_idx, size_t at, size_t len)
{
	DEBUG_HEAT_MAP&&ft_dprintf(2, HEAT_ASSIGN, player_idx, at, len);

	ft_memset(vm->heat_map + at, player_idx + 1, len);
}
