# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/04/10 21:41:30 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= "\>\< asm :"
EX		:= asm
NAME	:= build/$(EX)
LNKNAME	:= ../../$(EX)

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
			parser/args/utils.c \
			parser/args/dir.c \
			parser/args/ind.c \
			parser/args/reg.c \
			binary.c \
			error.c

LIBDIR	:= ../libs
LIBS	:= liblift libprintf

#DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
