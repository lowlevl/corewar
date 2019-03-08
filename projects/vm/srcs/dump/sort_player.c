/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:10:50 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 16:56:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

static void ft_swap(uint8_t *n1, uint8_t *n2)
{
	uint8_t t;

	t = *n1;
	*n1 = *n2;
	*n2 = t;
}

static void init_sorted_array(uint8_t *arr, uint8_t max)
{
	uint8_t i;

	i = 0;
	while (++i < max)
	{
		arr[i] = i;
	}
}

static void sort_arr(t_player *players, uint8_t *arr, uint8_t count)
{
	uint8_t i;
	uint8_t j;
	i = -1;
	while (++i < count)
	{
		j = 0;
		while (j < i)
		{
			if (players[arr[i]].id > players[arr[j]].id)
				ft_swap(arr + i, arr + j);
			j++;
		}
	}
}

void sort_player_by_index(t_vm *vm)
{
	init_sorted_array(vm->sorted_players_idx, vm->players_count);
	sort_arr(vm->players, vm->sorted_players_idx, vm->players_count);
}
