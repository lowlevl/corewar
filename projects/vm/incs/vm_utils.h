/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:36:29 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/13 13:40:55 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_UTILS_H
#define VM_UTILS_H

#include "struct.h"
#include "libpf.h"
#include "argv.h"

void print_winner(t_vm *vm);
void init_vm(t_vm *vm, int argc, char *argv[]);

#endif // !VM_UTILS_H
