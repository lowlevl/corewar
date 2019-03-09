/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:55:19 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 16:08:25 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

#include <libft.h>
#include <libpf.h>
#include "error.h"
#include "struct.h"
#include <errno.h>
#include <op.h>
#include <stdint.h>
#include <unistd.h>

#define BYTE_PER_LINE 64
#define BYTE_PRINT_LENGTH 3
#define LINE_LENGTH BYTE_PER_LINE *BYTE_PRINT_LENGTH

void		print_dump(void *mem);
void		print_memory(void *mem, int size, int line_size);
void		load_players(t_vm *vm);
void		load_player(t_vm *vm, int player_idx);
void		*get_champ_bin(t_vm *vm, int player_idx);
uint32_t	get_champ_size(t_vm *vm, int player_idx);
void		*get_start_in_memory(t_vm *vm, int player_idx);
void		sort_player_by_index(t_vm *vm);
#endif
