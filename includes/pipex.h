/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 19:07:44 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Bonus State (On/Off)
# ifndef BONUS
#  define BONUS 1
# endif

// System Libraries...
# include <libft.h>
# include <get_next_line.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex	t_pipex;

int		pipe_initialize(t_pipex *pipe, char **argv, int argc, char **env);
void	pipe_run(t_pipex *pipe);
void	pipe_close(t_pipex *pipe);
void	env_parse(t_pipex *pipex);
char	*env_cmd(t_pipex *pipex, char *cmd);
int		process_start(t_pipex *pipe, int id);
int		ft_file_open(char *file);
int		ft_file_create(char *file);
void	ft_file_close(int fd);
void	ft_putchr_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_write_err(char *str);

typedef struct s_pipex
{
	int		fd_input;
	int		fd_output;
	char	*path;
	char	**env;
	char	**cmds;
	int		cmdc;
}	t_pipex;

#endif