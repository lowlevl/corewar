/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:33:50 by glodi             #+#    #+#             */
/*   Updated: 2019/03/08 11:54:39 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	print_header(t_player *player)
{
	ft_printf("header:\n");
	ft_printf("\tmagic  = %#x\n", player->header.magic);
	ft_printf("\tprog_name = %s\n", player->header.prog_name);
	ft_printf("\tprog_size = %u\n", player->header.prog_size);
	ft_printf("\tcomment = %s\n", player->header.comment);
	ft_printf("end.\n");
}

void	print_vm(t_vm *vm)
{
	ft_printf("vm:\n");
	ft_printf("\tplayer_count = %u\n", vm->players_count);

	ft_printf("\tplayers: %#x\n", vm->players);

	if (vm->players[0].default_id)
		ft_printf("\t\t[0] id = %d\n", vm->players[0].default_id);
	else if (vm->players[0].specified_id)
		ft_printf("\t\t[0] id = %d\n", vm->players[0].specified_id);

	if (vm->players[1].default_id)
		ft_printf("\t\t[1]id = %d\n", vm->players[1].default_id);
	else if (vm->players[1].specified_id)
		ft_printf("\t\t[1] id = %d\n", vm->players[1].specified_id);

	if (vm->players[2].default_id)
		ft_printf("\t\t[2]id = %d\n", vm->players[2].default_id);
	else if (vm->players[2].specified_id)
		ft_printf("\t\t[2] id = %d\n", vm->players[2].specified_id);

	if (vm->players[3].default_id)
		ft_printf("\t\t[3]id = %d\n", vm->players[3].default_id);
	else if (vm->players[2].specified_id)
		ft_printf("\t\t[2] id = %d\n", vm->players[2].specified_id);

	ft_printf("\tdump: %u\n", vm->dump);
	ft_printf("\tregs: %#x\n", vm->regs);
}
