/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 11:53:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include <error.h>
# include <dump.h>

# include "struct.h"

# define ERR_PROC_MALL "malloc processes"
# define ERR_NEW_PROC_MALL "realloc new processes"

void init_processes(t_vm *vm);
void add_processes(t_player *player, uint16_t pc);

#endif // !CURSOR_H
