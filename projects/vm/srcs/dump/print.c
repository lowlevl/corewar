/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:47:04 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 11:49:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

static char get_hex_char(uint8_t val)
{
	if (val > 9)
		return val - 9 + 'a';
	return val + '0';
}

static void print_line(uint8_t *mem, int current_line)
{
	char line[LINE_LENGTH + 1];
	uint8_t val;
	size_t col;

	col = 0;
	while (col < BYTE_PER_LINE)
	{
		val = mem[col];
		line[col * 3] = get_hex_char(val & 0xf);
		line[col * 3 + 1] = get_hex_char(val & 0xf0 >> 4);
		line[col * 3 + 2] = ' ';
		col++;
	}
	line[LINE_LENGTH] = 0;
	ft_printf("%.8p: %s\n", current_line * BYTE_PER_LINE, line);
}

void print_dump(uint8_t *mem)
{
	size_t line;

	line = 0;
	ft_printf("ram: %u o/L\n", BYTE_PER_LINE);
	while (line * BYTE_PER_LINE <= MEM_SIZE - BYTE_PER_LINE)
	{
		print_line(mem + line * BYTE_PER_LINE, line);
		line++;
	}
}
