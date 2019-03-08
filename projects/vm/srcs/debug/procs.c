/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:59:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 12:05:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void print_proc(t_process *proc)
{
	ft_printf("proc: %p\n", proc);
	if (proc != NULL) {
		ft_printf("\tplayer_id: %%\n", proc->player_id);
		ft_printf("\tcursor_pos: %%\n", proc->cursor_pos);
		ft_printf("\tcarry: %%\n", proc->carry);
		ft_printf("\twaiting: %%\n", proc->waiting);
		ft_printf("\tcursor_start: %%\n", proc->cursor_start);
	}
}
