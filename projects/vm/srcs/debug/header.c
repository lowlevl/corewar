/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:00:34 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/29 10:45:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

#define PRINT_HEADER                                                           \
	"header:\n\tmagic  = %#x\n\tprog_name = %s\n\tprog_size = %u\n\tcomment "  \
	"= %s\nend.\n"

int print_header(t_player *player)
{
	return ft_dprintf(2, PRINT_HEADER, player->header.magic, player->header.prog_name,
		player->header.prog_size, player->header.comment);
}
