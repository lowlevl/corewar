/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/05 17:56:04 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

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
	while (++i < argc)
		init_player(vm, argv[i]);
}

int main(int argc, char *argv[])
{
	static t_vm	vm;

	errno = 0;
	init_vm(&vm, argc, argv);
	return (0);
}
