/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:45:56 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 16:57:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "struct.h"
# include <error.h>

# define ERR_PROC_MALL "malloc processes"

void init_cursor(t_player *players, uint8_t count);

#endif // !CURSOR_H
