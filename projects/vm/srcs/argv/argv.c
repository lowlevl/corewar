/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/30 15:06:33 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void		init_player(t_vm *vm, char *binary_path, int specified_id)
{
	t_player *player;

	if (vm->players_count == MAX_PLAYERS)
		set_errno_exit(E2BIG, ERR_TOO_MANY_PLAYERS);
	player = vm->players + vm->players_count;
	ft_bzero(player, sizeof(*player));
	player->file_name = binary_path;
	player->file_buffer = get_file_buffer(binary_path);
	player->header = *((t_header *)player->file_buffer);
	player->header.magic = BSWAP_32(player->header.magic);
	player->header.prog_size = BSWAP_32(player->header.prog_size);
	player->id = specified_id;
	vm->players_count++;
}
