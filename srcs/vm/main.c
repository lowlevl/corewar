/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:42:01 by glodi             #+#    #+#             */
/*   Updated: 2019/03/03 17:44:39 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	if_errno_printerr_exit()
{
	if (errno)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

static void *get_file_buffer(char *file_path)
{
	int			fd;
	off_t		file_size;
	void		*file_buffer;

	fd = open(file_path, O_RDONLY);

	file_size = lseek(fd, 0, SEEK_END); // get file end
	lseek(fd, 0, SEEK_SET); // step back
	if_errno_printerr_exit();
	file_buffer = malloc(file_size);
	read(fd, file_buffer, file_size);
	if_errno_printerr_exit();
	return (file_buffer);
}

static void init_player(t_vm *vm, char *binary_path)
{
	static nb = 0;
	static t_player	player;

	player.header = *((header_t*)get_file_buffer(binary_path));

	ft_printf("header:\n");
	ft_printf("\tmagic = %u\n", player.header.magic);
	ft_printf("\tprog_name = %s\n", player.header.prog_name);
	ft_printf("\tprog_size = %u\n", player.header.prog_size);
	ft_printf("\tcomment = %s\n", player.header.comment);
	ft_printf("end.\n");
}

static void init_vm(t_vm *vm, int argc, char *argv[])
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

	init_vm(&vm, argc, argv);
	return (0);
}
