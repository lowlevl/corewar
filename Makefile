# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodi <glodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/04 16:05:05 by glodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= corewar
NAME	:= corewar

OBJDIR	:= objs
INCDIR	:= incs

SRCDIR	:= srcs
SRCS	:= vm/main.c vm/debug.c vm/errors.c vm/file_utils.c

LIBDIR	:= libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
