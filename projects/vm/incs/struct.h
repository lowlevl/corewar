/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:07:53 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 20:24:22 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdint.h>
# include <op.h>

/*
** Struct definition
*/

typedef	struct	s_process {
	uint8_t		carry; // not sure the type is ok
	int32_t		waiting;
	uint16_t	cursor_start;
	uint16_t	cursor_pos;
	uint32_t	regs[REG_NUMBER];
}				t_process;

typedef struct	s_player {
	header_t	header;
	char		*file_name;
	char		*file_buffer;
	int32_t		id; // Start from 0,-1 if not set
	uint32_t	live_count;
	uint32_t	processes_count;
}				t_player;

typedef struct	s_vm {
	uint8_t		players_count;
	t_player	players[MAX_PLAYERS];
	uint8_t		sorted_players_idx[MAX_PLAYERS];

	uint64_t	dump; // wtf is this shit ???
	uint8_t		memory[MEM_SIZE];

	t_process	*processes;
	int			processes_count;
	int			cycle_count;
}				t_vm;

#endif
