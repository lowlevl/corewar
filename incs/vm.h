/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:16 by glodi             #+#    #+#             */
/*   Updated: 2019/03/06 15:34:25 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

/*
** System includes
*/
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

/*
** Our includes
*/
# include <op.h>
# include <libft.h>
# include <libpf.h>
# include <argv.h>
# include <struct.h>
# include <error.h>
# include <utils.h>
# include <debug.h>

void		load_players(t_vm *vm);
void		load_player(t_vm *vm, int player_idx);
void		*get_champ_bin(t_vm *vm, int player_idx);
uint32_t	get_champ_size(t_vm *vm, int player_idx);
void		*get_start_in_memory(t_vm *vm, int player_idx);

#endif
