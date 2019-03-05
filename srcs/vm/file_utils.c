/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:04:46 by glodi             #+#    #+#             */
/*   Updated: 2019/03/05 17:03:25 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int	get_fd(char *file_path)
{
	int			fd;

	fd = open(file_path, O_RDONLY);
	if_errno_printerr_exit();
	return (fd);
}

off_t	get_file_size(int fd)
{
	off_t		file_size;

	file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if_errno_printerr_exit();
	return (file_size);
}

void *get_file_buffer(char *file_path)
{
	int			fd;
	void		*file_buffer;
	off_t		file_size;

	fd = get_fd(file_path);
	file_size = get_file_size(fd);
	file_buffer = malloc(file_size);
	if_errno_printerr_exit();
	read(fd, file_buffer, file_size);
	if_errno_printerr_exit(); // need to free too...
	close(fd);
	if_errno_printerr_exit(); // need to free too...
	return (file_buffer);
}

