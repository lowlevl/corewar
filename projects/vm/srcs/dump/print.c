/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:47:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/02 12:01:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

static void add_hex_to_line(char *line, uint8_t val)
{
	line[0] = (val >> 4);
	line[1] = (val & 0xf);
	if (line[0] > 9)
		line[0] = line[0] - 10 + 'a';
	else
		line[0] += '0';
	if (line[1] > 9)
		line[1] = line[1] - 10 + 'a';
	else
		line[1] += '0';
	line[2] = ' ';
}

static inline int print_color(uint8_t val)
{
	if (val == 0)
		return (ft_printf("\e[0m"));
	if (val == 1)
		return (ft_printf("\e[31m"));
	if (val == 2)
		return (ft_printf("\e[32m"));
	if (val == 3)
		return (ft_printf("\e[36m"));
	if (val == 4)
		return( ft_printf("\e[35m"));
	return (0);
}

void print_memory(uint8_t *mem, uint8_t *heat_map)
{
	int  l;
	int  c;
	char line[BYTE_PRINT_LENGTH + 1];
	int8_t  lastheat;
	int idx;

	(void)heat_map;
	l = 0;
	ft_printf("index : 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f"
			  " 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f"
			  " 20 21 22 23 22 25 26 27 28 29 2a 2b 2c 2d 2e 2f"
			  " 30 31 32 33 33 35 36 37 38 39 3a 3b 3c 3d 3e 3f"
			  "\n");
	while (l < NB_LINE)
	{
		c = 0;
		ft_printf("0x%.4x: ", l * BYTE_PER_LINE);
		lastheat = -1;
		while (c < BYTE_PER_LINE)
		{
			idx = l * BYTE_PER_LINE + c;
			add_hex_to_line(line, mem[idx]);
			line[BYTE_PRINT_LENGTH] = 0;
			if (heat_map[idx] != lastheat)
			{
				lastheat = heat_map[idx];
				print_color(lastheat);
			}
			ft_printf("%s", line);
			c++;
		}
		ft_printf("\e[0m\n");
		++l;
	}
}
