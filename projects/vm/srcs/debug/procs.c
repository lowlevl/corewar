/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:59:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 11:18:42 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <debug.h>

void print_proc(t_process *proc)
{
	ft_printf("proc: %p\n", proc);
	if (proc != NULL) {
		ft_printf("\tplayer_id: %hhu\n", proc->player_id);
		ft_printf("\tcarry: %hhu\n", proc->carry);
		ft_printf("\twaiting: %d\n", proc->waiting);
		ft_printf("\tcursor_start: %u\n", proc->cursor_start);
		ft_printf("\tcursor_pos: %hu\n", proc->cursor_pos);
	}
}
