/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:25:31 by glodi             #+#    #+#             */
/*   Updated: 2019/03/11 12:02:48 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dump.h>

void	*get_pos_in_memory(void *mem, t_process *process)
{
	const int index = process->cursor_pos + process->cursor_start;

	return (mem + (index % MEM_SIZE));
}
