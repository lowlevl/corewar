/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:28:31 by glodi             #+#    #+#             */
/*   Updated: 2019/03/14 15:01:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODE_H
#define OPCODE_H

#include "bswap.h"
#include "dump.h"
#include "libft.h"
#include "libpf.h"
#include "proc.h"
#include "struct.h"
#include "vm_utils.h"

/**
 * utils read
 */
uint16_t read_arg(t_process *process, uint8_t *mem, int type);
uint8_t  read_octet_code(t_process *process, uint8_t *mem);
void read_in_memory(uint8_t *memory, uint8_t *buffer, uint8_t len, size_t at);

/**
 * utils get
 */
int		 get_type_arg(uint8_t co, uint8_t arg_number);
uint32_t get_reg(t_process *process, uint8_t reg_idx);
uint16_t get_indirect(size_t pos, uint8_t *memory);

/**
 * utils write
 */
void write_in_memory(uint8_t *mem, uint8_t *content, size_t len, size_t at);
void write_in_registre(t_process *process, uint16_t reg_idx, uint32_t value);

/**
 * utils other
 */
size_t get_restrict_address(size_t pos);

/**
 * command
 */
void exec_sti(t_vm *vm, t_process *process, const t_op *op);
void exec_live(t_vm *vm, t_process *process, const t_op *op);
void exec_and(t_vm *vm, t_process *process, const t_op *op);
void exec_zjump(t_vm *vm, t_process *process, const t_op *op);

#endif
