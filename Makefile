# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glodi <glodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 13:27:44 by lroux             #+#    #+#              #
#    Updated: 2019/04/30 14:40:29 by glodi            ###   ########.fr        #
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
PATHS.libft		+= libs/liblift

# Include core
include $(LIBDIR)/multi.mk
