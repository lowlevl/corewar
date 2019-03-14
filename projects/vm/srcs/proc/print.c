/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:52:38 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 15:01:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"

void process_print_taunt_buffer(t_vm *vm, t_process *process)
{
	t_player *player;

	player = find_player(vm->players, vm->players_count, process->player_id);
	process->taunt_buffer[process->taunt_size] = 0;
	if (player != NULL)
		ft_printf("le jouer %d (%s) dit: %s\n", process->player_id,
			player->header.prog_name, process->taunt_buffer);
	else
		ft_printf("un processus dit: %s\n", process->taunt_buffer);
	process->taunt_size = 0;
}
