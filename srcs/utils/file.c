/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/05 20:57:25 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

/*
 * The ft_open() function ...
 */
int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
		return (-1);
	return (1);
}

/*
 * The ft_close() function ...
 */
void	ft_close(int fd)
{
	close(fd);
}
