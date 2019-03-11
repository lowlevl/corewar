/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/09 20:22:32 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include <dump.h>
# include <error.h>
# include <debug.h>

# include "struct.h"

# define ERR_PROC_MALL "malloc processes"
# define ERR_NEW_PROC_MALL "realloc new processes"

void	init_processes(t_vm *vm);
void	init_process(t_vm *vm, int player_idx);

void	add_processes(t_vm *vm, uint16_t pc);
void	exec_cycle(t_vm *vm);
void	exec_player_processes(t_vm *vm, t_player *player);
void	exec_process(t_vm *vm, t_process *process);

#endif // !CURSOR_H
