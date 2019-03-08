/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:03:49 by glodi             #+#    #+#             */
/*   Updated: 2019/03/08 16:54:13 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void	init_default_ids(t_player *players, int players_count)
{
	int 		i;
	static int	default_id = 0;
	
	i = 0;
	while (i < players_count)
	{
		if (players[i].id != -1)
			i++;
		else if (is_unique_id(players, players_count, default_id))
		{
			players[i].id = default_id;
			i++;
		}
		else
			default_id++;
	}
}


int		is_unique_id(t_player *players, int players_count, int id)
{
	int i;

	i = 0;
	while (i < players_count)
	{
		if (id == (int)players[i].id)
			return (false);
		i++;
	}
	return (true);
}