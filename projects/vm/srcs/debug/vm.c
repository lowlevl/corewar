/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:33:50 by glodi             #+#    #+#             */
/*   Updated: 2019/03/08 12:00:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	print_vm(t_vm *vm)
{
	ft_printf("vm:\n");
	ft_printf("\tplayer_count = %u\n", vm->players_count);

	ft_printf("\tplayers: %#x\n", vm->players);
	if (vm->players[0].id)
		ft_printf("\t\t[0] id = %d\n", vm->players[0].id);
	if (vm->players[1].id)
		ft_printf("\t\t[1]id = %d\n", vm->players[1].id);
	if (vm->players[2].id)
		ft_printf("\t\t[2]id = %d\n", vm->players[2].id);
	if (vm->players[3].id)
		ft_printf("\t\t[3]id = %d\n", vm->players[3].id);

	ft_printf("\tdump: %u\n", vm->dump);
	ft_printf("\tregs: %#x\n", vm->regs);
}
