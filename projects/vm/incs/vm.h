/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:16 by glodi             #+#    #+#             */
/*   Updated: 2019/04/17 14:40:39 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

/*
** Our includes
*/

# include <libft.h>
# include <libpf.h>
# include <dump.h>
# include <op.h>
# include <argv.h>
# include <struct.h>
# include <error.h>
# include <utils.h>
# include <debug.h>
# include <proc.h>
# include <cycle.h>
# include <vm_utils.h>
# include "socket.h"
# include "heat_map.h"

/*
** System includes
*/

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

/*
** Defines
*/

# define CHAMP_TOO_LARGE "code too large"

#endif
