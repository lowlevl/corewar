/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:59:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/27 09:14:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void print_proc(t_process *proc)
{
	ft_dprintf(2, "proc: %p\n", proc);
	if (proc != NULL)
	{
		ft_dprintf(2, "\tid: %hhu\n", proc->id);
		ft_dprintf(2, "\tcarry: %hhu\n", proc->carry);
		ft_dprintf(2, "\texec_cycle: %d\n", proc->exec_cycle);
		ft_dprintf(2, "\tcursor_start: %x\n", proc->cursor_start);
		ft_dprintf(2, "\tcursor_pos: %hx\n", proc->cursor_pos);
		ft_dprintf(2, "\tplayer_id: %hu\n", proc->player_id);
		ft_dprintf(2, "\thave_live: %hu\n", proc->have_live);
	}
}
