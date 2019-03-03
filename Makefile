# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodi <glodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2019/03/03 15:49:15 by glodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT	:= corewar
NAME	:= corewar

OBJDIR	:= objs
INCDIR	:= incs

SRCDIR	:= srcs
SRCS	:= vm/main.c

LIBDIR	:= libs
LIBS	:= libft libpf

DEBUG	:= 1

# Include core
include $(LIBDIR)/project.mk
