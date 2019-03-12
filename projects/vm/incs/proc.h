/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/12 15:37:33 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROC_H
# define PROC_H

# include <dump.h>
# include <error.h>
# include <debug.h>
# include <opcode.h>

# include "struct.h"

# define ERR_PROC_MALL "malloc processes"
# define ERR_NEW_PROC_MALL "realloc new processes"

void	init_processes(t_vm *vm);
void	init_process(t_vm *vm, uint16_t cursor_start,int index,
	int32_t player_id);

void	add_processes(t_vm *vm, uint16_t pc, int id);

void	exec_cycle(t_vm *vm);
void	exec_process(t_vm *vm, t_process *process);
void	check_process(t_vm *vm, t_process *process);

void	process_move_cursor(t_process *process, off_t off);

#endif // !PROC_H
