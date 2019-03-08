/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:55:19 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 11:51:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdint.h>
# include <unistd.h>
# include <libpf.h>
# include <errno.h>
# include <op.h>
# include "struct.h"

# define BYTE_PER_LINE 64
# define BYTE_PRINT_LENGTH 3
# define LINE_LENGTH BYTE_PER_LINE * BYTE_PRINT_LENGTH

void	print_dump(uint8_t *mem);
void		load_players(t_vm *vm);
void		load_player(t_vm *vm, int player_idx);
void		*get_champ_bin(t_vm *vm, int player_idx);
uint32_t	get_champ_size(t_vm *vm, int player_idx);
void		*get_start_in_memory(t_vm *vm, int player_idx);

#endif
