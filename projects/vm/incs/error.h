/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:00:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 13:20:38 by glodi            ###   ########.fr       */
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
# define ERR_N_INVALID_HALF "Invalid value given to '-n'."
# define ERR_N_INVALID ERR_N_INVALID_HALF " It must be greater or equal than 0"
# define ERR_N_DUPLICATE_HALF "Duplication of value given to '-n'. "
# define ERR_N_DUPLICATE ERR_N_DUPLICATE_HALF " Each value must be unique"
# define ERR_SOCKET_IP "missing ip for --socket"
# define ERR_SOCKET_PORT "missing port for --socket"

/*
** Errors functions
*/
void	if_errno_printerr_exit(const char *error);
void	set_errno_exit(const int err_val, const char *msg);
void	exit_print_usage(void);

#endif
