/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:36:29 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/22 13:12:23 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_UTILS_H
#define VM_UTILS_H

#include "struct.h"
#include "libpf.h"
#include "argv.h"
#include "flags.h"

void print_winner(t_vm *vm);
void init_vm(t_vm *vm, int argc, char *argv[]);
t_player *find_player(t_player *players, size_t player_count, int32_t player_id);

#endif // !VM_UTILS_H
