/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:59:17 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/11 11:29:05 by glodi            ###   ########.fr       */
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
		ft_printf("\tcursor_start: %u\n", proc->cursor_start);
		ft_printf("\tcursor_pos: %hu\n", proc->cursor_pos);
	}
}
