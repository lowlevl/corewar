/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:47:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 16:19:13 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

void print_dump(void *mem)
{
	print_memory(mem, MEM_SIZE, 64);
}

void	print_memory(void *mem, int size, int line_size)
{
	int	i;

	i = 0;
	ft_printf("0x0000: ");
	while (i < size)
	{
		if (i % line_size == 0 && i != 0)
			ft_printf("\n%#.4x: ", i);
		ft_printf("%.2x ", ((unsigned char*)mem)[i]);
		++i;
	}
	ft_printf("\n");
}
