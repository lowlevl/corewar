/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:07:53 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/07 18:31:20 by glodi            ###   ########.fr       */
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
	uint8_t		player_id;
	uint16_t	cursor_pos;
	uint8_t		carry; // not sure the type is ok
	uint32_t	waiting;
	uint32_t	cursor_start;
}				t_process;

typedef struct	s_player {
	header_t	header;
	char		*file_name;
	char		*file_buffer;
	uint32_t	live_count;
	uint32_t	processes_count;
	t_process	*processes;
	uint32_t	id;
}				t_player;

typedef struct	s_vm {
	uint8_t		players_count;
	t_player	players[MAX_PLAYERS];
	uint64_t	dump;
	uint8_t		memory[MEM_SIZE];
	uint32_t	regs[REG_NUMBER];
}				t_vm;

#endif
