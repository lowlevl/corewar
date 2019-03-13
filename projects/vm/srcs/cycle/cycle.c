/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 13:11:59 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"
#include "libpf.h"

void setup_for_next_cycle(t_vm *vm)
{
	vm->next_check = vm->cycle_count + vm->cycle_to_die;
	vm->nb_check = 0;
	vm->nb_live_for_cycle = 0;
}

void check_players_have_live(t_vm *vm)
{
	uint8_t i;
	t_player *players;

	i = 0;
	players = vm->players;
	while (i < vm->players_count)
	{
		if (players[i].is_alive)
		{
			if (players[i].cycle_live_count == 0)
			{
				players[i].is_alive = 0;
				vm->players_alive--;
			}
			else
				players[i].cycle_live_count = 0;
		}
		i++;
	}
}

void check_cycle(t_vm *vm)
{
	if (vm->next_check == vm->cycle_count)
	{
		if (vm->nb_live_for_cycle >= NBR_LIVE || vm->nb_check >= MAX_CHECKS)
			vm->cycle_to_die -= CYCLE_DELTA;
		else
			vm->nb_check++;
		check_players_have_live(vm);
		setup_for_next_cycle(vm);
	}
}

void exec_cycle(t_vm *vm)
{
	uint64_t   i;
	t_process *process;

	i = 0;
	vm->cycle_count++;
	while (i < vm->processes_count)
	{
		process = vm->processes + i;
		exec_process(vm, process);
		i++;
	}
	check_cycle(vm);
}

void cycle_until_death(t_vm *vm)
{
	while (vm->players_alive > 0)
	{
		exec_cycle(vm);
	}
}

void cycle_until_dump(t_vm *vm)
{
	while (vm->cycle_count < vm->dump && vm->players_alive > 0)
	{
		exec_cycle(vm);
	}
}

void make_cycle(t_vm *vm)
{
	if (vm->dump == -1)
		cycle_until_death(vm);
	else
		cycle_until_dump(vm);
}
