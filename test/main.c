/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:53:50 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/27 16:39:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define HELLO "hello client\xff"
typedef struct sockaddr_in t_sockaddr_in;
typedef struct sockaddr	t_sockaddr;

void close_exit(int sock, int csock, int value) __attribute__((noreturn));

void close_exit(int sock, int csock, int value)
{
	printf("close server\n");

	if (sock >= 0)
		close(sock);
	if (csock >= 0)
		close(csock);
	exit(value);
}

int create_socket()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0)
	{
		perror("socket()");
		close_exit(sock, -1, errno);
	}
	return sock;
}

int setup_socket(int sock)
{
	int option = 1;

	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
	{
		perror("setsockopt()");
		close_exit(sock, -1, errno);
	}
	return 0;
}

void setup_interface(t_sockaddr_in *sin)
{
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = htonl(INADDR_ANY); // any addr
	sin->sin_port = htons(PORT);
}

int bind_interface_to_socket(int sock, t_sockaddr_in *sin)
{
	if (bind(sock, (t_sockaddr *)sin, sizeof(*sin)) < 0)
	{
		perror("bind()");
		close_exit(sock, -1, errno);
	}
	return 0;
}

int setup_listen_socket(int sock)
{
	if (listen(sock, 5) < 0)
	{
		perror("listen()");
		close_exit(sock, -1, errno);
	}
	return 0;
}

int accet_new_connexion(int sock, t_sockaddr_in *csin)
{
	int		  csock;
	socklen_t len = sizeof(*csin);

	csock = accept(sock, (t_sockaddr *)csin, &len);
	if (csock < 0)
	{
		perror("accept()");
		close_exit(sock, -1, errno);
	}
	return csock;
}

int send_message_to(int sock, int csock, void *msg, int flags)
{
	if (send(csock, msg, strlen(msg), flags) < 0)
	{
		perror("send()");
		close_exit(sock, csock, errno);
	}
	return 0;
}

int main(void)
{
	// create a socket
	int sock_fd = create_socket();
	int option = 1;

	setup_socket(sock_fd);
	// create interface
	t_sockaddr_in sin = {0};

	setup_interface(&sin);
	bind_interface_to_socket(sock_fd, &sin);

	// listen for connexion
	setup_listen_socket(sock_fd);

	t_sockaddr_in csin = {0};
	int			  csock_fd;
	socklen_t	 size_csin = sizeof(csin);

	csock_fd = accet_new_connexion(sock_fd, &csin);
	send_message_to(sock_fd, csock_fd, HELLO, 0);
	send_message_to(sock_fd, csock_fd, HELLO, 0);
	send_message_to(sock_fd, csock_fd, HELLO, 0);

	// shutdown(sock_fd, SHUT_RDWR);
	close_exit(sock_fd, csock_fd, 0);
	return 0;
}
