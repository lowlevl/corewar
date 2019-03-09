/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:00:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 15:11:13 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <libpf.h>

# define ERR_DUMP "Missing number for -dump"
# define ERR_N "Missing argument for '-n'"
# define ERR_N_INVALID "Invalid value given to '-n'. It must be greater or equal than 0"
# define ERR_N_DUPLICATE "Duplication of value given to '-n'. Each value must be unique"

/*
** Errors functions
*/
void	if_errno_printerr_exit(const char *error);
void	set_errno_exit(const int err_val, const char *msg);
void	exit_print_usage();

#endif
