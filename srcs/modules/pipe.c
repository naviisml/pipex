/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipe.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/07 12:42:42 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
 * The pipe_initialize() function checks if the first argument is
 * a valid file, after this, we check if the output file exists,
 * and create a new file if the file doesn't exist.
 * 
 * After this, we loop through the argument list (except for the
 * first and last argument) and put these in a array in the t_pipex
 * struct.
 */
int	pipe_initialize(t_pipex *pipe, char **argv, int argc, char **env)
{
	int		i;

	pipe->env = env;
	pipe->fd_input = ft_file_open(argv[1], O_RDWR);
	pipe->fd_output = ft_file_open(argv[argc], O_RDWR | O_CREAT | O_TRUNC);
	if (pipe->fd_input < 0)
		return (ft_write_err("Err: Input file doesn't exist."));
	if (pipe->fd_output < 0)
		return (ft_write_err("Err: Output file can't be opened/created."));
	i = 2;
	pipe->cmds = malloc((argc - 1) * sizeof(char *));
	if (!pipe->cmds)
		return (0);
	while (i < argc)
	{
		pipe->cmds[i - 2] = argv[i];
		i++;
	}
	pipe->cmdc = (i - 2);
	return (1);
}

/*
 * The pipe_close() function closes the files and free's the allocated
 * memory.
 */
void	pipe_close(t_pipex *pipex)
{
	ft_file_close(pipex->fd_input);
	ft_file_close(pipex->fd_output);
	free(pipex->cmds);
	pipex->cmdc = 0;
}
