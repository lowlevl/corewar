# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/13 09:54:55 by fbenneto         ###   ########.fr        #
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
	opcode/sti.c \
	opcode/live.c \
	opcode/get.u.c \
	opcode/read.u.c \
	opcode/write.u.c \
	proc/proc.c \
	proc/cursor.c \
	utils/file_utils.c \

LIBDIR	:= ../libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
