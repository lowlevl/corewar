/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:49:40 by glodi             #+#    #+#             */
/*   Updated: 2019/03/06 13:21:43 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>

void	if_errno_printerr_exit(const char *error)
{
	if (errno || error)
	{
		if (error)
			perror(error);
		else
			ft_printf("Error: %s\n", strerror(errno));
		exit(1);
	}
}

void	set_erno_and_print_error(const int err_val, const char *msg)
{
	errno = err_val;
	if_errno_printerr_exit(msg);
}
