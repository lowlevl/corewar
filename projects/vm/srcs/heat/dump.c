/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:03:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/17 13:22:05 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dump.h"
#include "heat_map.h"

static inline void	add_val_to_line(char *line, uint8_t val)
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

void				dump_heat_map(uint8_t *heat_map)
{
	char	line[LINE_LENGTH + 1];
	size_t	l;
	size_t	c;

	l = 0;
	while (l < NB_LINE)
	{
		c = 0;
		while (c < BYTE_PER_LINE)
		{
			add_val_to_line(
				line + c * BYTE_PRINT_LENGTH, heat_map[l * BYTE_PER_LINE + c]);
			c++;
		}
		line[c * BYTE_PRINT_LENGTH] = 0;
		ft_printf("0x%.4x: %s\n", l * BYTE_PER_LINE, line);
		l++;
	}
}
