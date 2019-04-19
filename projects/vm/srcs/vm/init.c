/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:13:51 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/19 17:10:42 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_utils.h"
#include <time.h>

void	init_vm(t_vm *vm, int argc, char *argv[])
{
	int	i;

	i = 0;
	vm->dump = -1;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->next_check = CYCLE_TO_DIE;
	vm->nb_check = 0;
	if (argc < 2)
		exit_print_usage();
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			handle_option(vm, argc, argv, &i);
		else
			init_player(vm, argv[i], -1);
	}
	init_default_ids(vm->players, vm->players_count);
	srand(time(0));
	DEBUG_VM && print_vm(vm);
}
