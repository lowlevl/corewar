/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:03:51 by fbenneto          #+#    #+#             */
/*   Updated: 2019/03/06 12:04:42 by fbenneto         ###   ########.fr       */
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
void	*get_file_buffer(char *file_path);
size_t	little_to_big_endian(size_t n);

#endif
