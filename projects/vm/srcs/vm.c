/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/08 11:48:34 by fbenneto         ###   ########.fr       */
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
	// print_dump(vm.memory);
	return (0);
}
