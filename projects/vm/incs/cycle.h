/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:48:52 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/21 16:45:25 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLE_H
#define CYCLE_H

#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include "flags.h"

void		exec_process(t_vm *vm, t_process *process);
const t_op *get_opcode(uint8_t val);
void		make_cycle(t_vm *vm);

#endif // !CYCLE_H
