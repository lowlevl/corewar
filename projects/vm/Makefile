# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/15 12:52:41 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= "⚙️  vm :"
NAME	:= build/corewar
LNKNAME	:= ../../corewar

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= vm.c \
	argv/argv.c \
	argv/id.c \
	cycle/cycle.c \
	cycle/utils.c \
	debug/header.c \
	debug/procs.c \
	debug/vm.c \
	dump/print.c \
	dump/load_player.c \
	dump/sort_player.c \
	dump/wrappers.c \
	error/error.c \
	opcode/_get.u.c \
	opcode/_read.u.c \
	opcode/_write.u.c \
	opcode/_other.u.c \
	opcode/sti.c \
	opcode/live.c \
	opcode/and.c \
	opcode/add.c \
	opcode/ldi.c \
	opcode/lldi.c \
	opcode/sub.c \
	opcode/or.c \
	opcode/xor.c \
	opcode/zjump.c \
	opcode/aff.c \
	opcode/ld.c \
	opcode/fork.c \
	opcode/lfork.c \
	proc/proc.c \
	proc/print.c \
	proc/cursor.c \
	utils/file_utils.c \
	vm/init.c \
	vm/find.c \
	vm/winner.c \

LIBDIR	:= ../libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
