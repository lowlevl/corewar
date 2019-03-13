/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:06:59 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 13:21:33 by fbenneto         ###   ########.fr       */
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
# include <bswap.h>

/*
** Init functions
*/

void handle_option(t_vm *vm, const int argc, char **argv, int *index);

void	init_player(t_vm *vm, char *binary_path, int player_id);
void	init_vm(t_vm *vm, int argc, char *argv[]);

void	init_default_ids(t_player *players, int players_count);
int		is_unique_id(t_player *players, int players_count, int id);

#endif
