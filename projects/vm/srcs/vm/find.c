/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:57:23 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 16:43:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"

t_player *find_player(t_player *players, size_t player_count, int32_t player_id)
{
	size_t i;

	i = 0;
	while (i < player_count)
	{
		if (players[i].id == player_id)
			return players + i;
		i++;
	}
	return NULL;
}
