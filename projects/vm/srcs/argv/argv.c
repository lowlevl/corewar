/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 16:50:37 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void	init_player(t_vm *vm, char *binary_path, int specified_id)
{
	t_player	*player;

	player = vm->players + vm->players_count ;
	ft_bzero(player, sizeof(*player));
	player->file_name = binary_path;
	player->file_buffer = get_file_buffer(binary_path);
	player->header = *((header_t *)player->file_buffer);
	player->header.magic = little_to_big_endian(player->header.magic);
	player->header.prog_size = little_to_big_endian(player->header.prog_size);
	player->id = specified_id;
	print_header(player);
	vm->players_count++;
}

static void handle_option(t_vm *vm, const int argc, char **argv, int *index)
{
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
			init_player(vm, argv[*index + 1], ft_atoi(argv[*index]));
			*index = *index + 1;
		}
		else
			set_errno_exit(EINVAL, ERR_N);
	}
}

void init_vm(t_vm *vm, int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc < 2)
		exit_print_usage();
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			handle_option(vm, argc, argv, &i);
		else
			init_player(vm, argv[i], -1);
	}
	init_default_ids(vm->players, vm->players_count);
	print_vm(vm); // Debug
}
