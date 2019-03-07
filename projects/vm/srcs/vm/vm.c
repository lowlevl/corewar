/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/07 11:12:27 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int main(int argc, char *argv[])
{
	static t_vm	vm;

	vm.dump = -1;
	init_vm(&vm, argc, argv);
	load_players(&vm);
	init_processes(vm.players, vm.players_count);
	// if (vm.dump == 0)
	print_dump(vm.memory);
	return (0);
}

void		load_players(t_vm *vm)
{
	int i;

	i = -1;
	while (++i < vm->players_count)
		load_player(vm, i);
}

void		load_player(t_vm *vm, int player_idx)
{
	void		*champ_bin;
	uint32_t	champ_size;
	void		*start_in_memory;

	champ_bin = get_champ_bin(vm, player_idx);
	champ_size = get_champ_size(vm, player_idx);
	start_in_memory = get_start_in_memory(vm, player_idx);
	ft_memcpy(start_in_memory, champ_bin, champ_size);
}

void		*get_champ_bin(t_vm *vm, int player_idx)
{
	return (vm->players[player_idx].file_buffer + sizeof(header_t));
}

uint32_t	get_champ_size(t_vm *vm, int player_idx)
{
	return ((uint32_t)vm->players[player_idx].header.prog_size);
}

void		*get_start_in_memory(t_vm *vm, int player_idx)
{
	return (vm->memory + ((MEM_SIZE / vm->players_count) * player_idx));
}
