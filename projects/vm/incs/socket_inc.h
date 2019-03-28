/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_inc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:50:14 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/28 15:55:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_INC_H
#define SOCKET_INC_H

#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_CLIENT_SOCKET 1
#define SOCK_SEND_FLAGS 0

typedef struct sockaddr_in t_sockaddr_in;
typedef struct sockaddr	t_sockaddr;

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

#endif // !SOCKET_INC_H
