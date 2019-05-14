# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <lroux@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 14:04:31 by lroux             #+#    #+#              #
#    Updated: 2019/04/29 14:04:34 by lroux            ###   ########.fr        #
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
