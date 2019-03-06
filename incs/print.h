/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:55:19 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 16:29:05 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdint.h>
# include <unistd.h>
# include <libpf.h>
# include <op.h>

# define BYTE_PER_LINE 64
# define BYTE_PRINT_LENGTH 3
# define LINE_LENGTH BYTE_PER_LINE * BYTE_PRINT_LENGTH

void	print_dump(uint8_t *mem);

#endif
