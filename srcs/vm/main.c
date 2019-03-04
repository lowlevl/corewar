/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/04 17:12:04 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void init_player(t_vm *vm, char *binary_path)
{
	static t_player	player;

	player.file_buffer = get_file_buffer(binary_path);
	player.header = *((header_t*)player.file_buffer);

	/* debug */
	print_header(&player);
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
