/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:34:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/14 12:02:07 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "proc.h"

void	process_move_cursor(t_process *process, off_t off)
{
	process->cursor_pos = (process->cursor_pos + off) % MEM_SIZE;
}

void	process_set_cursor_pos(t_process *process, size_t pos)
{
	process->cursor_pos = pos % MEM_SIZE;
}
