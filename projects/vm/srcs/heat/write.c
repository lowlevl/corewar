/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:34:08 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 13:23:40 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heat_map.h"

static inline size_t	get_index(size_t i)
{
	return (i % MEM_SIZE);
}

void					assign_player_to_area(
		uint8_t *map, int player_idx, size_t at, size_t len)
{
	size_t i;

	DEBUG_HEAT_MAP && ft_dprintf(2, HEAT_ASSIGN, player_idx, at, len);
	i = 0;
	player_idx++;
	while (i < len)
	{
		map[get_index(at + i)] = player_idx;
		i++;
	}
}
