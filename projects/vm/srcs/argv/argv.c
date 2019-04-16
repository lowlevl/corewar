/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:05:58 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 14:44:24 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <argv.h>

void		init_player(t_vm *vm, char *binary_path, int specified_id)
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

void		handle_option_3(t_vm *vm, const int argc, char **argv, int *index)
{
	(void)argc;
	if (ft_strcmp(HEAT_OPT, argv[*index]) == 0)
	{
		vm->dump_heat = 1;
	}
	else if (ft_strcmp(H_OPT, argv[*index]) == 0)
	{
		ft_usage();
		exit(0);
	}
	else
	{
		ft_dprintf(2, "%s: %s unknow option\n", argv[0], argv[*index]);
		ft_usage();
		exit(1);
	}
}

void		handle_option_2(t_vm *vm, const int argc, char **argv, int *index)
{
	if (ft_strcmp(SOCKET_OPT, argv[*index]) == 0)
	{
		*index = *index + 1;
		if (argc > *index)
			vm->socket.ip = argv[*index];
		else
			return (set_errno_exit(EINVAL, ERR_SOCKET_IP));
		*index = *index + 1;
		if (argc > *index)
			vm->socket.port = ft_atoi(argv[*index]);
		else
			return (set_errno_exit(EINVAL, ERR_SOCKET_PORT));
		vm->socket.enable = ENABLE_SOCKET;
	}
	else
		handle_option_3(vm, argc, argv, index);
}

void		handle_option_1(t_vm *vm, const int argc, char **argv, int *index)
{
	int id;

	if (ft_strcmp(N_OPT, argv[*index]) == 0)
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
	else
		handle_option_2(vm, argc, argv, index);
}

void		handle_option(t_vm *vm, const int argc, char **argv, int *index)
{
	if (ft_strcmp(DUMP_OPT, argv[*index]) == 0)
	{
		*index = *index + 1;
		if (*index < argc)
			vm->dump = ft_atoi(argv[*index]);
		else
			set_errno_exit(EINVAL, ERR_DUMP);
	}
	else
		handle_option_1(vm, argc, argv, index);
}
