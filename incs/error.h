/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:00:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 13:13:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <libpf.h>

/*
** Errors functions
*/
void	if_errno_printerr_exit(const char *error);
void	set_erno_and_print_error(const int err_val, const char *msg);

#endif
