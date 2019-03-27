/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:20:03 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/27 13:07:01 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FALGS_H
#define FALGS_H

/**
** 0 for off
** 1 for on
*/

#define DEBUG_READ 1
#define DEBUG_WRITE 1
#define DEBUG_GET 1
#define DEBUG_TYPE 1
#define DEBUG_R_FC 1
#define DEBUG_CR_P 1
#define DEBUG_EXE 1
#define DEBUG_CYCLE 1
#define DEBUG_CARRY 1
#define DEBUG_CHECK 1

#define READ_PREFIX "\e[31mREAD\e[0m   : "
#define WRITE_PREFIX "\e[32mWRITE\e[0m  : "
#define GET_PREFIX "\e[33mGET\e[0m    : "
#define TYPE_PREFIX "\e[34mTYPE\e[0m   : "
#define FUNC_PREFIX "\e[35mFUNC\e[0m   : "
#define CURSOR_PREFIX "\e[36mCURSOR\e[0m : "
#define EXE_PREFIX "\e[37mEXE\e[0m    : "
#define CYCLE_PREFIX "\e[91mCYCLE\e[0m  : "
#define CARRY_PREFIX "\e[92mCARRY\e[0m  : "
#define CHECK_PREFIX "\e[93mCHECK\e[0m  : "

#define CHECK_TEMPLATE                                                         \
	CHECK_PREFIX "current(%zd) next(%zd) die(%zd) check(%d) live(%zu)\n"

#define CARRY_TEMPLATE CARRY_PREFIX "carry(%d)\n"

#define CURSOR_TEMPLATE CURSOR_PREFIX "pos(%x) opc(%hhx)\n"

#define EXE_TEMPLATE EXE_PREFIX "proc(%#hhx)(%s) at(%u)(%x)\n"
#define EXE_NEXT_TEMPLATE EXE_PREFIX "next_exec(%#hhx)(%s) at(%u)\n"

#define TYPE_TEMPLATE_3 TYPE_PREFIX "0(%d) 1(%d) 2(%d)\n"
#define TYPE_TEMPLATE_2 TYPE_PREFIX "0(%d) 1(%d)\n"
#define TYPE_TEMPLATE_1 TYPE_PREFIX "0(%d)\n"

#define READ_TEMPLATE READ_PREFIX "at(%x) type(%d) val(%x)\n"
#define READ_TEMPLATE_NOT READ_PREFIX "%d not found\n"

#define GET_TEMPLATE_REG GET_PREFIX "reg: reg_id(%d) val(%x)\n"
#define GET_TEMPLATE_REG_NOT GET_PREFIX "reg: reg_id(%d) not in bound\n"

#endif // !FALGS_H
