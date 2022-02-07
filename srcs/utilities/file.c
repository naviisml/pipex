/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/07 11:25:39 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
 * The ft_file_open() function ...
 */
int	ft_file_open(char *file, int flags)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd < 0)
		return (-1);
	return (fd);
}

/*
 * The ft_file_close() function ...
 */
void	ft_file_close(int fd)
{
	close(fd);
}
