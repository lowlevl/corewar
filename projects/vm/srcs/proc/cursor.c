/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:34:09 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/12 15:36:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "proc.h"

void	process_move_cursor(t_process *process, off_t off)
{
	process->cursor_pos = (process->cursor_pos + off) % MEM_SIZE;
}
