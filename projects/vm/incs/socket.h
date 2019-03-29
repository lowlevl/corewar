/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:49:47 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 15:11:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
#define SOCKET_H

#include "error.h"
#include "flags.h"
#include "socket_inc.h"
#include "struct.h"

/**
 * utils
 */
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

#endif // !SOCKET_H
