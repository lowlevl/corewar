/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:07 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 09:49:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cycle.h"

void exec_cycle(t_vm *vm)
{
	int		   i;
	t_process *process;

	i = 0;
	vm->cycle_count++;
	while (i < vm->processes_count)
	{
		process = vm->processes + i;
		exec_process(vm, process);
		i++;
	}
}
