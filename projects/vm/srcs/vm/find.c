/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:57:23 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/14 11:51:28 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"

t_player	*find_player(
		t_player *players, size_t player_count, int32_t player_id)
{
	size_t i;

	i = 0;
	while (i < player_count)
	{
		if (players[i].id == player_id)
			return (players + i);
		i++;
	}
	return (NULL);
}

int			get_rank_player_id(
	uint8_t *sorted_player_idx, t_player *list, t_player *tofind, uint8_t count)
{
	uint8_t i;

	i = 0;
	while (i < count)
	{
		if (list[sorted_player_idx[i]].id == tofind->id)
			return (i);
		i++;
	}
	return (-1);
}
