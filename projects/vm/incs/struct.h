/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:07:53 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 15:44:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <netinet/in.h>
#include <op.h>
#include <stdint.h>
#include <sys/socket.h>
#include <unistd.h>

/*
** Struct definition
*/

#define MAX_CLIENT_SOCKET 1
#define TAUNT_BUFFER_SIZE 128

typedef struct sockaddr_in t_sockaddr_in;
typedef struct sockaddr	t_sockaddr;

typedef struct s_process
{
	uint8_t			  carry; // not sure the type is ok
	int64_t			  exec_cycle;
	uint16_t		  cursor_start;
	uint16_t		  cursor_pos; // pc
	uint32_t		  regs[REG_NUMBER];
	char			  taunt_buffer[TAUNT_BUFFER_SIZE];
	uint16_t		  taunt_size;
	int				  player_id;
	uint8_t			  have_live;
	size_t			  id;
	struct s_process *next;
} t_process;

typedef struct s_player
{
	header_t header;
	char *   file_name;
	char *   file_buffer;
	int32_t  id; // Start from 0,-1 if not set
	uint32_t total_live_count;
	uint32_t processes_count;
} t_player;

typedef struct s_sock_inter
{
	int			  sock;
	t_sockaddr_in inter;
} t_sock_inter;

typedef struct s_socket
{
	char *		 ip;
	int16_t		 port;
	int			 enable : 1;
	t_sock_inter server;

	t_sock_inter client[MAX_CLIENT_SOCKET];
	int			 nb_client;
} t_socket;

typedef struct s_vm
{
	uint8_t  players_count;
	t_player players[MAX_PLAYERS];
	uint8_t  sorted_players_idx[MAX_PLAYERS];
	uint32_t last_player_report_as_live;

	int64_t dump;
	uint8_t memory[MEM_SIZE];

	t_process *processes;
	uint64_t   processes_count;

	uint32_t nb_check;
	int64_t  next_check;
	int32_t  cycle_to_die;
	int64_t  cycle_count;
	uint64_t nb_live_for_cycle;

	t_socket socket;
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
