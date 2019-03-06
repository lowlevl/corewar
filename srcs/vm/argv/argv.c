/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 13:36:07 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void init_player(t_vm *vm, char *binary_path, int player_id)
{
	static int player_count = 0;
	t_player player;

	ft_bzero(&player, sizeof(player));
	player.file_buffer = get_file_buffer(binary_path);
	player.header = *((header_t *)player.file_buffer);
	player.header.magic = little_to_big_endian(player.header.magic);
	player.header.prog_size = little_to_big_endian(player.header.prog_size);
	player.id = player_count;
	vm->players[player_count] = player;

	if (player_id != -1)
		player.id = player_id;

	print_header(&vm->players[player_count]);

	player_count++;
}

static void handle_option(t_vm *vm, const int argc, char **argv, int *index)
{
	if (ft_strcmp("dump", argv[*index] + 1) == 0)
	{
		if (*index < argc)
		{
			*index = *index + 1;
			vm->dump = ft_atoi(argv[*index]);
		}
		else
			set_erno_and_print_error(EINVAL, ERR_DUMP);
	}
	else if (ft_strcmp("n", argv[*index] + 1) == 0)
	{
		*index = *index + 1;
		if (*index + 1 < argc)
		{
			init_player(vm, argv[*index + 1], ft_atoi(argv[*index]));
			*index = *index + 1;
		}
		else
			set_erno_and_print_error(EINVAL, ERR_N);
	}
}

void init_vm(t_vm *vm, int argc, char *argv[])
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			handle_option(vm, argc, argv, &i);
		}
		else
		{
			init_player(vm, argv[i], -1);
		}
	}
	print_vm(vm);
}
