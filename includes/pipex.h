/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/05 20:54:55 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// REMOVE THIS LINE!!
# include <stdio.h>

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

int		ft_open(char *file);
void	ft_close(int fd);

#endif