/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:49:40 by glodi             #+#    #+#             */
/*   Updated: 2019/03/04 17:06:05 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	if_errno_printerr_exit(char *error)
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

