/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:00:34 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/16 18:37:44 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

#define H1 "header:\n\tmagic  = %#x\n\tprog_name = %s\n\tprog_size = %u\n\t"
#define H2 "comment = %s\nend.\n"
#define PRINT_HEADER H1 H2

int	print_header(t_player *player)
{
	return (ft_dprintf(2, PRINT_HEADER, player->header.magic,
			player->header.prog_name, player->header.prog_size,
			player->header.comment));
}
