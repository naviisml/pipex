/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/06 01:41:25 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

/*
 * The ft_file_open() function ...
 */
int	ft_file_open(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (-1);
	return (1);
}

/*
 * The ft_file_create() function ...
 */
int	ft_file_create(char *file)
{
	int	fd;

	fd = open(file, O_CREAT, 0644);
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
