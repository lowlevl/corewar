/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:59:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/26 11:22:52 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void print_proc(t_process *proc)
{
	ft_printf("proc: %p\n", proc);
	if (proc != NULL)
	{
		ft_printf("\tcarry: %hhu\n", proc->carry);
		ft_printf("\texec_cycle: %d\n", proc->exec_cycle);
		ft_printf("\tcursor_start: %x\n", proc->cursor_start);
		ft_printf("\tcursor_pos: %hx\n", proc->cursor_pos);
		ft_printf("\tplayer_id: %hu\n", proc->player_id);
		ft_printf("\thave_live: %hu\n", proc->have_live);
	}
}
