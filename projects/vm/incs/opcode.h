/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:28:31 by glodi             #+#    #+#             */
/*   Updated: 2019/03/11 15:29:05 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODE_H
# define OPCODE_H

# include "struct.h"
# include "libft.h"
# include "libpf.h"
# include "dump.h"
# include "bswap.h"

void exec_sti(t_vm *vm, t_process *process, const t_op *op);

#endif