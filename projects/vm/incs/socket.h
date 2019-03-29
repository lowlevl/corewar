/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:49:47 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 09:24:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
#define SOCKET_H

#include "error.h"
#include "socket_inc.h"

int send_message_to(t_sock_inter *dest, void *msg, socklen_t len);
int send_message_to_all(t_socket *sock, void *msg, socklen_t len);

int accept_new_connexion(t_socket *sock);

int set_listen_socket(t_socket *sock);

int bind_setup_inter(t_socket *sock);

int setup_server_interface(t_socket *sock);

int setup_server_socket(t_socket *sock);
int create_server_socket(t_socket *sock);

int disable_socket(t_socket *sock);
int close_clients(t_socket *sock);

#endif // !SOCKET_H
