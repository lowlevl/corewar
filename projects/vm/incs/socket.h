/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:49:47 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 16:21:12 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
#define SOCKET_H

#include "socket_inc.h"

int send_message_to(t_sock_inter dest, void *msg, size_t len);
int accept_new_connexion(t_sock_inter *server, t_sock_inter *empty_inter);
int set_listen_socket(t_sock_inter *server);
int bind_setup_inter(t_sock_inter *server);
int setup_server_interface(t_socket *socket);
int setup_server_socket(t_sock_inter *server);
int create_server_socket(t_socket *server);

#endif // !SOCKET_H
