/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:47:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/01 10:14:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

static void	add_hex_to_line(char *line, uint8_t val)
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

void		print_memory(uint8_t *mem, uint8_t *heat_map)
{
	int		l;
	int		c;
	char	line[LINE_PREFIX + LINE_LENGTH + 1];

	l = 0;
	ft_printf("index : 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f"
			" 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f"
			" 20 21 22 23 22 25 26 27 28 29 2a 2b 2c 2d 2e 2f"
			" 30 31 32 33 33 35 36 37 38 39 3a 3b 3c 3d 3e 3f"
			"\n");
	while (l < NB_LINE)
	{
		c = 0;
		while (c < BYTE_PER_LINE)
		{
			add_hex_to_line(
				line + c * BYTE_PRINT_LENGTH, mem[l * BYTE_PER_LINE + c]);
			c++;
		}
		line[c * BYTE_PRINT_LENGTH] = 0;
		ft_printf("0x%.4x: %s\n", l * BYTE_PER_LINE, line);
		++l;
	}
	ft_printf("\n");
}
