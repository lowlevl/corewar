/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:00:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 15:25:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <libpf.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

# define ERR_DUMP "Missing number for -dump"
# define ERR_N "Missing argument for '-n'"
# define ERR_N_INVALID "Invalid value given to '-n'. It must be greater or equal than 0"
# define ERR_N_DUPLICATE "Duplication of value given to '-n'. Each value must be unique"
# define ERR_SOCKET_IP "missing ip for --socket"
# define ERR_SOCKET_PORT "missing port for --socket"

/*
** Errors functions
*/
void	if_errno_printerr_exit(const char *error);
void	set_errno_exit(const int err_val, const char *msg);
void	exit_print_usage();

#endif
