/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:57:16 by glodi             #+#    #+#             */
/*   Updated: 2019/03/03 17:41:36 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <libft.h>
# include <libpf.h>
# include <fcntl.h>
# include <unistd.h>
# include <op.h>

typedef struct	s_player {
	header_t	header;
	void		*file_buff;
}				t_player;

typedef struct	s_vm {
	t_player	players[MAX_PLAYERS];
	char		memory[MEM_SIZE];
}				t_vm;

#endif
