/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 13:50:32 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void init_player(t_vm *vm, char *binary_path, int specified_id)
{
	t_player *player;

	player = vm->players + vm->players_count;
	ft_bzero(player, sizeof(*player));
	player->file_name = binary_path;
	player->file_buffer = get_file_buffer(binary_path);
	player->header = *((header_t *)player->file_buffer);
	player->header.magic = bswap_32(player->header.magic);
	player->header.prog_size = bswap_32(player->header.prog_size);
	player->id = specified_id;
	vm->players_count++;
}

void handle_option(t_vm *vm, const int argc, char **argv, int *index)
{
	int id;

	if (ft_strcmp("dump", argv[*index] + 1) == 0)
	{
		*index = *index + 1;
		if (*index < argc)
			vm->dump = ft_atoi(argv[*index]);
		else
			set_errno_exit(EINVAL, ERR_DUMP);
	}
	else if (ft_strcmp("n", argv[*index] + 1) == 0)
	{
		*index = *index + 1;
		if (*index + 1 < argc)
		{
			id = ft_atoi(argv[*index]);
			if (!is_unique_id(vm->players, vm->players_count, id))
				set_errno_exit(EINVAL, ERR_N_DUPLICATE);
			init_player(vm, argv[*index + 1], id);
			*index = *index + 1;
		}
		else
			set_errno_exit(EINVAL, ERR_N);
	}
}
