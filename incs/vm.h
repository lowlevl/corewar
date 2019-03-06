/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:16 by glodi             #+#    #+#             */
/*   Updated: 2019/03/06 10:12:29 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

/*
** System includes
*/
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

/*
** Our includes
*/
# include <op.h>
# include <libft.h>
# include <libpf.h>
# include <argv.h>
# include <struct.h>

/*
** Init functions
*/
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
