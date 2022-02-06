/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 14:05:37 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
 * The ft_putchr_fd() function ...
 */
void	ft_putchr_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
 * The ft_putstr_fd() function ...
 */
void	ft_putstr_fd(char *str, int fd)
{
	while (*str != '\0')
	{
		ft_putchr_fd(*str, fd);
		str++;
	}
}

/*
 * The ft_write_err() function ...
 */
int	ft_write_err(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchr_fd('\n', 2);
	return (0);
}
