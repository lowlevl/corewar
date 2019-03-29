/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:08:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 10:42:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
#define DEBUG_H

#include "struct.h"
#include <libpf.h>
#include <stdlib.h>

/*
** Debug functions
*/
int print_header(t_player *player);
int print_vm(t_vm *vm);
int print_players(t_player *players);
int print_player(t_player *player, char *prefix);
int print_proc(t_process *proc);
int debug_socket(t_socket *sock);

/*
** Used functions
*/

int print_loaded_players(t_vm *vm);
int print_loaded_player(t_player *player);

#endif
