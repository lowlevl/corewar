/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 10:54:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void init_player(t_vm *vm, char *binary_path)
{
	static int	player_count = 0;
	t_player	player;

	ft_bzero(&player, sizeof(player));
	player.file_buffer = get_file_buffer(binary_path);
	player.header = *((header_t*)player.file_buffer);
	player.header.magic = little_to_big_endian(player.header.magic);
	player.header.prog_size = little_to_big_endian(player.header.prog_size);
	vm->players[player_count] = player;

	print_header(&vm->players[player_count]);

	player_count++;
}

void init_vm(t_vm *vm, int argc, char *argv[])
{
	int i;

	/* We start from av[1] */
	i = 0;
	while (++i < argc) {
		ft_printf("%s\n", argv[i]);
		if (argv[i][0] == '-')
		{
			if (ft_strcmp("dump", argv[i] + 1) == 0) {
				i++;
				ft_printf("%s\n", argv[i]);
			}
		}
		else
		{
			init_player(vm, argv[i]);
		}
	}
}
