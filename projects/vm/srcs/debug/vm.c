/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:33:50 by glodi             #+#    #+#             */
/*   Updated: 2019/03/08 17:13:24 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	print_vm(t_vm *vm)
{
	ft_printf("vm:\n");
	ft_printf("\tplayer_count = %u\n", vm->players_count);

	print_players(vm->players);

	ft_printf("\tdump = %u\n", vm->dump);
	ft_printf("\tregs = %#x\n", vm->regs);
}

void	print_players(t_player *players)
{
	int i;

	ft_printf("\tPlayers[]:\n");
	i = 0;
	while (i < MAX_PLAYERS && players[i].file_name)
	{
		print_player(&players[i], "\t\t");
		i++;
	}
}

void	print_player(t_player *player, char *prefix)
{
	ft_printf("%s%p:\n", prefix, player);
	ft_printf("%s\tfile_name = %s\n", prefix, player->file_name);
	ft_printf("%s\tid = %d\n", prefix, player->id);
}