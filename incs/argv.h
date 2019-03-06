/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:06:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 12:11:46 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H

# include "struct.h"
# include <libft.h>
# include <libpf.h>
# include <utils.h>
# include <error.h>
# include <debug.h>

/*
** Init functions
*/
void init_player(t_vm *vm, char *binary_path);
void init_vm(t_vm *vm, int argc, char *argv[]);

#endif
