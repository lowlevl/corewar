/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:16 by glodi             #+#    #+#             */
/*   Updated: 2019/03/04 17:08:55 by glodi            ###   ########.fr       */
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
typedef struct	s_player {
	header_t	header;
	char		*file_buffer;
}				t_player;

typedef struct	s_vm {
	t_player		players[MAX_PLAYERS];
	uint8_t			memory[MEM_SIZE];
	// pc;
	// carry;
	// unsigned int	regs[REG_NUMBER] : REG_SIZE;
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
off_t	get_file_size(int fd, char *file_path);
void	*get_file_buffer(char *file_path);

/*
** Errors functions
*/
void	if_errno_printerr_exit();

/*
** Debug functions
*/
void	print_header(t_player *player);

#endif
