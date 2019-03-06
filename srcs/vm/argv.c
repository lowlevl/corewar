/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 10:06:29 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void init_vm(t_vm *vm, int argc, char *argv[])
{
	int i;

	/* We start from av[1] */
	i = 0;
	while (++i < argc)
		init_player(vm, argv[i]);
}
