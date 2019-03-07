# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/06 17:06:49 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= corewar
NAME	:= corewar

OBJDIR	:= objs
INCDIR	:= incs

SRCDIR	:= srcs
SRCS	:= vm/vm.c \
	vm/debug/debug.c \
	vm/error/errors.c \
	vm/utils/file_utils.c \
	vm/argv/argv.c \
	vm/dump/print.c \
	vm/proc/proc.c \

LIBDIR	:= libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
