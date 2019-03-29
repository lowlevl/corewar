# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/29 09:25:44 by fbenneto         ###   ########.fr        #
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

CYCLE_SRC := cycle/cycle.c \
	cycle/utils.c \

DEBUG_SRC := debug/header.c \
	debug/procs.c \
	debug/vm.c \

VM_SRC := 	vm/init.c \
	vm/find.c \
	vm/winner.c \

SOCKET_SRC := socket/accept.c \
	socket/bind.c \
	socket/listen.c \
	socket/send.c \
	socket/socket.c \
	socket/interface.c \
	socket/shutdown.c \

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

LIBDIR	:= ../libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
