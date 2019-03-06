/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:07:53 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 10:11:27 by fbenneto         ###   ########.fr       */
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
	uint16_t	pc;
	uint8_t		carry; // not sure the type is ok
}				t_process;

typedef struct	s_player {
	header_t	header;
	char		*file_buffer;
	uint32_t	live_count;
	uint32_t	processes_count;
	t_process	*processes;
}				t_player;

typedef struct	s_vm {
	uint8_t		players_count;
	t_player	players[MAX_PLAYERS];
	uint8_t		memory[MEM_SIZE];
	uint32_t	regs[REG_NUMBER];
}				t_vm;

#endif
