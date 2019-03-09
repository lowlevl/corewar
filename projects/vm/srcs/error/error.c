/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:49:40 by glodi             #+#    #+#             */
/*   Updated: 2019/03/08 14:42:13 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>

void	if_errno_printerr_exit(const char *error)
{
	if (errno)
	{
		if (error)
			perror(error);
		else
			ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

void	set_errno_exit(const int err_val, const char *msg)
{
	errno = err_val;
	if_errno_printerr_exit(msg);
}

void	exit_print_usage()
{
	ft_printf("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]"
			" ...\n");
	exit(1);
}

