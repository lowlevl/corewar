/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:33:50 by glodi             #+#    #+#             */
/*   Updated: 2019/03/06 12:12:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void	print_header(t_player *player)
{
	ft_printf("header:\n");
	ft_printf("\tmagic  = %#x\n", player->header.magic);
	ft_printf("\tprog_name = %s\n", player->header.prog_name);
	ft_printf("\tprog_size = %u\n", player->header.prog_size);
	ft_printf("\tcomment = %s\n", player->header.comment);
	ft_printf("end.\n");
}
