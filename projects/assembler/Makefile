# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/27 15:49:34 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= "⚙️  assembler :"
NAME	:= build/asm
LNKNAME	:= ../../asm

INCDIR	:= incs
SRCDIR	:= srcs
OBJDIR	:= build/obj

SRCS	:= \
			main.c \
			lexer.c \
			parser/parser.c \
			parser/utils.c \
			parser/inst.c \
			parser/cmd.c \
			parser/args/dir.c \
			parser/args/ind.c \
			parser/args/reg.c \
			binary.c \
			error.c

LIBDIR	:= ../libs
LIBS	:= liblift libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
