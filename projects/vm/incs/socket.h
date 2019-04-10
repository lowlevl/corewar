/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:49:47 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/10 13:10:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
#define SOCKET_H

#include "error.h"
#include "flags.h"
#include "socket_inc.h"
#include "struct.h"

#define AUTO_CLEAN __attribute__((cleanup(clean_simple_ptr)))

/**
 * utils
 */
void clean_simple_ptr(void *p);

unsigned char *encode_base64(void *src, size_t len, size_t *out_len);

int send_message_to(t_sock_inter *dest, void *msg, socklen_t len);
int send_message_to_all(t_socket *sock, void *msg, socklen_t len);

int create_server_socket(t_socket *sock);
int setup_server_socket(t_socket *sock);
int setup_server_interface(t_socket *sock);
int bind_setup_inter(t_socket *sock);
int set_listen_socket(t_socket *sock);
int disable_socket(t_socket *sock);

int close_clients(t_socket *sock);
int accept_new_connexion(t_socket *sock);
int accept_all_client(t_socket *sock);

/**
 * other
 */
int send_players(t_vm *vm);
int send_winner(t_player *player, t_socket *socket);
int send_procs(t_vm *vm);
int send_live(t_socket *socket, int32_t player_id);
int send_taunt(t_socket *socket, t_process *process);
int send_all_mem(t_vm *vm);
int send_mem_chunk(t_vm *vm, size_t idx, size_t chunk_size);
int send_all_map(t_vm *vm);
int send_map_chunk(t_vm *vm, size_t idx, size_t chunk_size);
int send_end(t_socket *socket);
int send_cycle(t_socket *socket, t_vm *vm);

#endif // !SOCKET_H
