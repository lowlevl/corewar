/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:16 by glodi             #+#    #+#             */
/*   Updated: 2019/03/05 17:41:56 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

/*
** System includes
*/
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <errno.h>

/*
** Our includes
*/
# include <op.h>
# include <libft.h>
# include <libpf.h>

/*
** Struct definition
*/
typedef	struct	s_process {
	uint8_t		player_id;
	uint16_t	pc;
	uint8_t		carry; // not sure the type is ok
}				t_process;

typedef struct	s_player {
	header_t	header;
	char		*file_buffer;
	uint32_t	live_count;
	uint32_t	processes_count;
	t_process	*processes;
}				t_player;

typedef struct	s_vm {
	uint8_t		players_count;
	t_player	players[MAX_PLAYERS];
	uint8_t		memory[MEM_SIZE];
	uint32_t	regs[REG_NUMBER];
}				t_vm;

/*
** Init functions
*/
void init_vm(t_vm *vm, int argc, char *argv[]);
void init_player(t_vm *vm, char *binary_path);

/*
** Utils functions
*/
int		get_fd(char *file_path);
off_t	get_file_size(int fd);
void	*get_file_buffer(char *file_path);
size_t	little_to_big_endian(size_t n);

/*
** Errors functions
*/
void	if_errno_printerr_exit();

/*
** Debug functions
*/
void	print_header(t_player *player);

#endif
