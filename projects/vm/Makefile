# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/04/05 16:43:13 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= "⚙️  vm :"
NAME	:= build/corewar
LNKNAME	:= ../../corewar

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

OPCODE_SRC := opcode/_get.u.c \
	opcode/_read.u.c \
	opcode/_write.u.c \
	opcode/_other.u.c \
	opcode/sti.c \
	opcode/live.c \
	opcode/st.c \
	opcode/and.c \
	opcode/add.c \
	opcode/ldi.c \
	opcode/lldi.c \
	opcode/sub.c \
	opcode/lld.c \
	opcode/or.c \
	opcode/xor.c \
	opcode/zjump.c \
	opcode/aff.c \
	opcode/ld.c \
	opcode/fork.c \
	opcode/lfork.c \

DUMP_SRC := dump/print.c \
	dump/load_player.c \
	dump/sort_player.c \
	dump/wrappers.c \

PROC_SRC := proc/proc.c \
	proc/print.c \
	proc/cursor.c \

ARGV_SRC :=	argv/argv.c \
	argv/id.c \
	argv/usage.c \

CYCLE_SRC := cycle/cycle.c \
	cycle/utils.c \

DEBUG_SRC := debug/header.c \
	debug/procs.c \
	debug/vm.c \
	debug/socket.c \

VM_SRC := 	vm/init.c \
	vm/find.c \
	vm/winner.c \

SOCKET_SRC := socket/_accept.u.c \
	socket/_bind.u.c \
	socket/_listen.u.c \
	socket/_send.u.c \
	socket/_socket.u.c \
	socket/_interface.u.c \
	socket/_shutdown.u.c \
	socket/player.c \
	socket/proc.c \
	socket/live.c \
	socket/taunt.c \
	socket/player_map.c \
	socket/mem.c \
	socket/end.c \
	socket/cycle.c \

HEAT_MAP := heat/write.c \
	heat/dump.c \

SRCS	:= vm.c \
	error/error.c \
	proc/utils.c \
	utils/file_utils.c \
	$(OPCODE_SRC) \
	$(DUMP_SRC) \
	$(PROC_SRC) \
	$(ARGV_SRC) \
	$(CYCLE_SRC) \
	$(DEBUG_SRC) \
	$(VM_SRC) \
	$(SOCKET_SRC) \
	$(HEAT_MAP) \

LIBDIR	:= ../libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
