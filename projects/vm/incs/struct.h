/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:07:53 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/01 11:11:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <op.h>
# include <stdint.h>
# include <unistd.h>

# include "socket_inc.h"

/*
** Struct definition
*/

# define TAUNT_BUFFER_SIZE 128

typedef struct	s_process
{
	uint8_t				carry;
	int64_t				exec_cycle;
	uint16_t			cursor_start;
	uint16_t			cursor_pos;
	uint32_t			regs[REG_NUMBER];
	char				taunt_buffer[TAUNT_BUFFER_SIZE];
	uint16_t			taunt_size;
	int					player_id;
	uint8_t				have_live;
	size_t				id;
	struct s_process	*next;
}				t_process;

typedef struct	s_player
{
	t_header	header;
	char		*file_name;
	char		*file_buffer;
	int32_t		id;
	uint32_t	total_live_count;
	uint32_t	processes_count;
}				t_player;

typedef struct	s_vm
{
	uint8_t		players_count;
	t_player	players[MAX_PLAYERS];
	uint8_t		sorted_players_idx[MAX_PLAYERS];
	uint32_t	last_player_report_as_live;

	int64_t		dump;
	unsigned	dump_heat : 1;
	uint8_t		memory[MEM_SIZE];
	uint8_t		heat_map[MEM_SIZE];

	t_process	*processes;
	uint64_t	processes_count;

	uint32_t	nb_check;
	int64_t		next_check;
	int32_t		cycle_to_die;
	int64_t		cycle_count;
	int64_t		jump_to;
	unsigned	disable_jump : 1;
	uint64_t	nb_live_for_cycle;

	t_socket	socket;
	unsigned random_talk: 1;
	unsigned print_live: 1;
}				t_vm;

typedef struct	s_op
{
	char		*name;
	uint8_t		args_count;
	uint8_t		args_type[MAX_ARGS_NUMBER];
	uint32_t	opcode;
	uint32_t	duration;
	char		*long_name;
	uint8_t		has_opt;
	uint8_t		direct_size;
}				t_op;

typedef struct	s_ops
{
	char	*name;
	void	(*f)(t_vm *vm, t_process *process, const t_op *op);
}				t_ops;

typedef struct	s_coord
{
	size_t	at;
	size_t	len;
}				t_coord;

#endif
