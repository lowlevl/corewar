/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:59:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/05/06 11:07:44 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

#define ONE "proc\tid: %hhu\n\tcarry: %hhu\n\texec_cycle: %d\n\tcursor_start: "
#define TWO "%x\n\tcursor_pos: %hx\n\tplayer_id: %hu\n\thave_live: %hu\n"
#define PROC ONE TWO

int	print_proc(t_process *proc)
{
	if (proc != NULL)
	{
		return (ft_dprintf(2, PROC, proc->id, proc->carry, proc->exec_cycle,
			proc->cursor_start, proc->cursor_pos, proc->player_id,
			proc->have_live));
	}
	return (0);
}
