/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/06 17:14:33 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
 * The pipe_initialize() function checks if the first argument is
 * a valid file, after this, we check if the output file exists,
 * and create a new file if the file doesn't exist.
 * 
 * After this, we loop through the argument list (except for the
 * first and last argument) and put these in a array in the t_pipex
 * struct.
 */
static int	pipe_initialize(t_pipex *pipe, char **argv, int argc)
{
	int		i;

	pipe->fd_input = ft_file_open(argv[1]);
	pipe->fd_output = ft_file_open(argv[argc]);
	if (pipe->fd_input < 0)
		return (ft_write_err("Err: File doesn't exist."));
	if (pipe->fd_output < 0)
	{
		pipe->fd_output = ft_file_create(argv[argc]);
		if (pipe->fd_output < 0)
			return (ft_write_err("Err: Could't create output file."));
	}
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
static void	pipe_close(t_pipex *pipe)
{
	ft_file_close(pipe->fd_input);
	ft_file_close(pipe->fd_output);
	free(pipe->cmds);
	pipe->cmdc = 0;
}

/*
 * The pipex program ...
 */
int	main(int argc, char **args)
{
	t_pipex	pipe;
	int		res;

	if (argc < 5)
		return (ft_write_err("Err: Missing arguments"));
	res = pipe_initialize(&pipe, args, (argc - 1));
	if (!res)
		return (0);
	debug_pipex_struct(&pipe);
	pipe_close(&pipe);
	return (0);
}
