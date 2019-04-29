# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <lroux@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 13:27:44 by lroux             #+#    #+#              #
#    Updated: 2019/04/29 14:30:11 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= project

SUBDIR	:= projects
LIBDIR	:= $(SUBDIR)/libs

PROJS			+= asm
PATHS.asm		+= assembler

PROJS			+= corewar
PATHS.corewar	+= vm

PROJS			+= libft
PATHS.libft		+= libs/libft

# Include core
include $(LIBDIR)/multi.mk
