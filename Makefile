# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/06 10:13:37 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= corewar
NAME	:= corewar

OBJDIR	:= objs
INCDIR	:= incs

SRCDIR	:= srcs
SRCS	:= vm/main.c \
	vm/debug.c \
	vm/errors.c \
	vm/file_utils.c \
	vm/argv.c

LIBDIR	:= libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
