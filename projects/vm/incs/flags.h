/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:20:03 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/30 21:34:43 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

/*
** 0 for off
** 1 for on
*/

# define DEBUG_PROC 0
# define DEBUG_VM 0
# define DEBUG_READ  0
# define DEBUG_WRITE 0
# define DEBUG_GET   0
# define DEBUG_TYPE  0
# define DEBUG_R_FC  0
# define DEBUG_CR_P  0
# define DEBUG_EXE   0
# define DEBUG_CYCLE 0
# define DEBUG_CARRY 0
# define DEBUG_CHECK 0
# define DEBUG_SOCKET_SEND 0
# define DEBUG_SOCKET_SETUP 0
# define DEBUG_SOCKET_CO 0
# define DEBUG_HEAT_MAP 0
# define DEBUG_SOCKET_RECV 0
# define DEBUG_SET_JUMP 0
# define DEBUG_STEP 0

# define READ_PREFIX           "\e[31mREAD\e[0m       │ "
# define WRITE_PREFIX          "\e[32mWRITE\e[0m      │ "
# define GET_PREFIX            "\e[33mGET\e[0m        │ "
# define TYPE_PREFIX           "\e[34mTYPE\e[0m       │ "
# define FUNC_PREFIX           "\e[35mFUNC\e[0m       │ "
# define CURSOR_PREFIX         "\e[36mCURSOR\e[0m     │ "
# define EXE_PREFIX            "\e[37mEXE\e[0m        │ "
# define CYCLE_PREFIX          "\e[91mCYCLE\e[0m      │ "
# define CARRY_PREFIX          "\e[92mCARRY\e[0m      │ "
# define CHECK_PREFIX          "\e[93mCHECK\e[0m      │ "
# define SOCKET_SEND_PREFIX    "\e[94mSOCK SEND\e[0m  │ "
# define SOCKET_SETUP_PREFIX   "\e[95mSOCK SETUP\e[0m │ "
# define SOCKET_CO_PREFIX      "\e[96mSOCK CO\e[0m    │ "
# define HEAT_PREFIX     "\e[38;5;202mHEAT MAP 🔥\e[0m │ "
# define SOCKET_RE_PREFIX "\e[38;5;46mSOCK RECV\e[0m  │ "
# define PROC_PRE         "\e[38;5;57mPROC\e[0m       │ "
# define JUMP_PRE        "\e[38;5;127mJUMP\e[0m       │ "
# define STEP_PRE         "\e[38;5;93mSTEP\e[0m       │ "

# define INTERNAL_1 "current(%zd) next(%zd) die(%zd) check(%d) live(%zu)\n"
# define CHECK_TEMPLATE CHECK_PREFIX INTERNAL_1

# define CARRY_TEMPLATE CARRY_PREFIX "carry(%d)\n"

# define CURSOR_TEMPLATE CURSOR_PREFIX "pos(%x) opc(%hhx)\n"

# define EXE_TEMPLATE EXE_PREFIX "proc(%#hhx)(%s) at(%u)(%x)\n"
# define EXE_NEXT_TEMPLATE EXE_PREFIX "next_exec(%#hhx)(%s) at(%u)\n"

# define TYPE_TEMPLATE_3 TYPE_PREFIX "0(%d) 1(%d) 2(%d)\n"
# define TYPE_TEMPLATE_2 TYPE_PREFIX "0(%d) 1(%d)\n"
# define TYPE_TEMPLATE_1 TYPE_PREFIX "0(%d)\n"

# define READ_TEMPLATE READ_PREFIX "at(%x) type(%d) val(%x)\n"
# define READ_TEMPLATE_NOT READ_PREFIX "%d not found\n"

# define REG "reg: reg_id(%d) val(%x)\n"
# define REG_NOT "reg: reg_id(%d) not in bound\n"

# define GET_TEMPLATE_REG GET_PREFIX REG
# define GET_TEMPLATE_REG_NOT GET_PREFIX REG_NOT

# define WRITE_REG WRITE_PREFIX REG
# define WRITE_REG_NOT WRITE_PREFIX REG_NOT
# define WRITE_MEM WRITE_PREFIX "at(%x) len(%zu) content(%zx)\n"

# define SOCKET_SHUTDOWN SOCKET_SETUP_PREFIX "shutdown server socket\n"
# define SOCKET_CLOSE SOCKET_SETUP_PREFIX "close client socket\n"
# define SOCKET_CREATE SOCKET_SETUP_PREFIX "create server socket\n"
# define SOCKET_SETUP SOCKET_SETUP_PREFIX "setup server socket\n"
# define INTERNAL_2 "setup server interface %s:%d (%x) (%x)\n"
# define SOCKET_INTERFACE SOCKET_SETUP_PREFIX INTERNAL_2
# define SOCKET_BIND SOCKET_SETUP_PREFIX "bind socket to interface\n"

# define SOCKET_LISTEN SOCKET_CO_PREFIX "set listen incomming co to %u client\n"
# define SOCKET_NEW_CO SOCKET_CO_PREFIX "accept new connexion %o:%d\n"
# define INTERNAL_3 "waiting for new connexion, timeout in (%u sec) (%u usec)\n"
# define SOCKET_WAITING SOCKET_CO_PREFIX INTERNAL_3
# define SOCKET_TIMEOUT SOCKET_CO_PREFIX "timeout new connexion\n"

# define SOCKET_SEND SOCKET_SEND_PREFIX "msg(%.*s) len(%d)\n"
# define SOCKET_PLAYER SOCKET_SEND_PREFIX "player(%s)\n"

# define HEAT_ASSIGN HEAT_PREFIX "player(%u) at(%zu) len(%zu)\n"

# define SOCKET_RECV SOCKET_RE_PREFIX "message(%s) len(%d)\n"

# define JUMP JUMP_PRE "to(%d)\n"

# define D_STEP STEP_PRE "cycle(%d)\n"
#endif
