/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:08:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 16:06:47 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "struct.h"
# include <libpf.h>
# include <stdlib.h>

/*
** Debug functions
*/
void	print_header(t_player *player);
void	print_vm(t_vm *vm);
void	print_players(t_player *players);
void	print_player(t_player *player, char *prefix);
void	print_proc(t_process *proc);

/*
** Used functions
*/


void	print_loaded_players(t_vm *vm);
void	print_loaded_player(t_player *player);

#endif
