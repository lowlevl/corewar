/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_inc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:50:14 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 14:28:07 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_INC_H
# define SOCKET_INC_H

# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <unistd.h>
# include <sys/select.h>

# define MAX_CLIENT_SOCKET 1
# define SOCKET_SYNC 1
# define SOCK_SEND_FLAGS 0

# define ENABLE_SOCKET 1
# define DISABLE_SOCKET 0
# define ALLOW_REUSE_ADDR 1

# define TIMEOUT_SEC 10
# define TIMEOUT_USEC 0

# define HEADER_SOCKET "xxxx"

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr	t_sockaddr;
typedef struct timeval	t_timeout;

typedef struct	s_sock_inter {
	int				sock;
	t_sockaddr_in	inter;
	unsigned		disable : 1;
}				t_sock_inter;

typedef struct	s_socket {
	char			*ip;
	int16_t			port;
	uint8_t			enable : 1;
	t_sock_inter	server;
	t_sock_inter	clients[MAX_CLIENT_SOCKET];
	uint16_t		nb_client;
}				t_socket;

#endif
