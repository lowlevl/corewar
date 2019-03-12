/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:07:53 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/12 14:03:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <op.h>
#include <stdint.h>

/*
** Struct definition
*/

typedef struct s_process
{
	uint8_t  carry; // not sure the type is ok
	int64_t  exec_cycle;
	uint16_t cursor_start;
	uint16_t cursor_pos; // pc
	uint32_t regs[REG_NUMBER];
	int		 player_id;
} t_process;

typedef struct s_player
{
	header_t header;
	char *   file_name;
	char *   file_buffer;
	int32_t  id; // Start from 0,-1 if not set
	uint32_t live_count;
	uint32_t processes_count;
} t_player;

typedef struct s_vm
{
	uint8_t  players_count;
	t_player players[MAX_PLAYERS];
	uint8_t  sorted_players_idx[MAX_PLAYERS];

	int64_t dump;
	uint8_t memory[MEM_SIZE];

	t_process *processes;
	int		   processes_count;
	int64_t	cycle_count;
} t_vm;

typedef struct s_op
{
	char *   name;
	uint8_t  args_count;
	uint8_t  args_type[MAX_ARGS_NUMBER];
	uint32_t opcode;
	uint32_t duration;
	char *   long_name;
	uint8_t  has_opt;
	uint8_t  direct_size; // Need verif
} t_op;

typedef struct s_ops
{
	char *name;
	void (*f)(t_vm *vm, t_process *process, const t_op *op);
} t_ops;

#endif
