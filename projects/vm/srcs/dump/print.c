/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:47:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 12:07:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

void print_dump(void *mem)
{
	print_memory(mem, MEM_SIZE, BYTE_PER_LINE);
}

void	print_memory(void *mem, int size, int line_size)
{
	int	i;

	i = 0;
	ft_printf("index : 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f"
		" 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f"
		" 20 21 22 23 22 25 26 27 28 29 2a 2b 2c 2d 2e 2f"
		" 30 31 32 33 33 35 36 37 38 39 3a 3b 3c 3d 3e 3f"
		"\n\n0x0000: ");
	while (i < size)
	{
		if (i % line_size == 0 && i != 0)
			ft_printf("\n%#.4x: ", i);
		ft_printf("%.2x ", ((unsigned char*)mem)[i]);
		++i;
	}
	ft_printf("\n");
}
