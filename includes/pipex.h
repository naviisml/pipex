/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/06 17:19:05 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef DEBUG
#  define DEBUG	1
# endif

// REMOVE THIS LINE!!
# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		fd_input;
	int		fd_output;
	char	**cmds;
	int		cmdc;
}	t_pipex;

int		ft_file_open(char *file);
int		ft_file_create(char *file);
void	ft_file_close(int fd);

void	ft_putchr_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_write_err(char *str);

void	debug_pipex_struct(t_pipex *pipe);

#endif