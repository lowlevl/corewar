/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:04:46 by glodi             #+#    #+#             */
/*   Updated: 2019/04/30 15:35:37 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			get_fd(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if_errno_printerr_exit(file_path);
	return (fd);
}

off_t		get_file_size(int fd)
{
	off_t	file_size;

	file_size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if_errno_printerr_exit(NULL);
	return (file_size);
}

static void	check_file_size(const char *file_path, off_t file_size)
{
	if (file_size < (off_t)sizeof(t_header))
	{
		ft_dprintf(2, "%s ", file_path);
		errno = EINVAL;
		if_errno_printerr_exit("file too small");
	}
}

void		*get_file_buffer(char *file_path, off_t *file_size)
{
	int		fd;
	void	*file_buffer;

	fd = get_fd(file_path);
	*file_size = get_file_size(fd);
	check_file_size(file_path, *file_size);
	file_buffer = ft_calloc(1, *file_size + 1);
	if_errno_printerr_exit(NULL);
	read(fd, file_buffer, *file_size);
	if_errno_printerr_exit(NULL);
	close(fd);
	if_errno_printerr_exit(NULL);
	return (file_buffer);
}

size_t		little_to_big_endian(size_t n)
{
	return ((n & 0xff) << 16
		| (n & 0xff00) << 8
		| (n & 0xff0000) >> 8
		| (n & 0xff000000) >> 24);
}
