/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:28:31 by glodi             #+#    #+#             */
/*   Updated: 2019/03/12 13:29:13 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODE_H
# define OPCODE_H

# include "struct.h"
# include "libft.h"
# include "libpf.h"
# include "dump.h"
# include "bswap.h"

/**
 * utils
 */
int get_type_arg(uint8_t co, uint8_t arg_number);
uint16_t read_arg(uint8_t **pos, int type);
uint32_t get_reg(t_process *process, uint8_t reg_idx);
uint8_t read_octet_code(uint8_t **pos);

/**
 * command
 */
void exec_sti(t_vm *vm, t_process *process, const t_op *op);

#endif
