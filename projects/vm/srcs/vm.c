/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/11 10:34:02 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int main(int argc, char *argv[])
{
	static t_vm	vm;

	vm.dump = -1;
	init_vm(&vm, argc, argv);
	load_players(&vm);
	sort_player_by_index(&vm);
	print_loaded_players(&vm);
	init_processes(&vm);
	exec_cycle(&vm);
	// if (vm.dump == 0)
		// print_dump(vm.memory);
	return (0);
}
