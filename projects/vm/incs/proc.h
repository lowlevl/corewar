/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/26 17:05:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROC_H
#define PROC_H

#include <debug.h>
#include <dump.h>
#include <error.h>
#include <opcode.h>

#include "struct.h"

#define ERR_PROC_MALL "malloc processes"
#define ERR_NEW_PROC_MALL "new processes"

void init_processes(t_vm *vm);
void init_process(
	t_process **head, uint16_t cursor_start, int32_t player_id);

void copy_process(t_vm *vm, t_process *process, size_t pos);
void delete_process(t_process **head);

void exec_cycle(t_vm *vm);
void exec_process(t_vm *vm, t_process *process);
void check_process(t_vm *vm, t_process *process);
void filter_process_have_live(t_vm *vm);

/**
 * Print
 */
void process_print_taunt_buffer(t_vm *vm, t_process *process);

/**
 * Cursor
 */
void process_move_cursor(t_process *process, off_t off);
void process_set_cursor_pos(t_process *process, size_t pos);

#endif // !PROC_H
