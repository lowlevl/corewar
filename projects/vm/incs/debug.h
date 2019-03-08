/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:08:42 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/08 12:03:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "struct.h"
# include <libpf.h>
# include <stdlib.h>

/*
** Debug functions
*/
void	print_header(t_player *player);
void	print_vm(t_vm *vm);
void	print_proc(t_process *proc);

#endif
