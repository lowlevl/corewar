/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:03:51 by fbenneto          #+#    #+#             */
/*   Updated: 2019/04/30 15:36:19 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

/*
** Utils functions
*/
int		get_fd(char *file_path);
off_t	get_file_size(int fd);
void	*get_file_buffer(char *file_path, off_t *file_size);
size_t	little_to_big_endian(size_t n);

#endif
