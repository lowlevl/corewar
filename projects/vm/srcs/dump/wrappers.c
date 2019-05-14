/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:25:31 by glodi             #+#    #+#             */
/*   Updated: 2019/03/12 15:00:30 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

void	*get_pos_in_memory(void *mem, t_process *process)
{
	return (mem + get_idx_in_memory(process));
}

size_t	get_idx_in_memory(t_process *process)
{
	return ((process->cursor_start + process->cursor_pos) % MEM_SIZE);
}
