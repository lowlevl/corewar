/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:26:13 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/12 16:37:06 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "opcode.h"

static size_t get_index(size_t i)
{
	return i % MEM_SIZE;
}

void write_in_memory(uint8_t *mem, uint8_t *content, size_t len, size_t at)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		mem[get_index(at + i)] = content[i];
		i++;
	}
}
