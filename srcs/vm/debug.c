/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:33:50 by glodi             #+#    #+#             */
/*   Updated: 2019/03/05 17:55:44 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

size_t	little_to_big_endian(size_t n)
{
	return ((n & 0xff) << 16
		| (n & 0xff00) << 8
		| (n & 0xff0000) >> 8
		| (n & 0xff000000) >> 24);
}

void	print_header(t_player *player)
{
	ft_printf("header:\n");
	ft_printf("\tmagic  = %#x\n", player->header.magic);
	ft_printf("\tprog_name = %s\n", player->header.prog_name);
	ft_printf("\tprog_size = %u\n", player->header.prog_size);
	ft_printf("\tcomment = %s\n", player->header.comment);
	ft_printf("end.\n");
}

