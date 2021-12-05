/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/05 21:15:31 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
 * The pipe_setup() function gets the first and last argument from argv,
 * and checks if the files exist.
 * 
 * After this, we loop through the rest of the arguments passed in the
 * program, and put them one-by-one in a list.
 */
static int	pipe_setup(t_pipex *pipe, char **argv, int argc)
{
	int		i;

	pipe->fd_input = ft_open(argv[1]);
	pipe->fd_output = ft_open(argv[argc]);
	if (pipe->fd_input < 0 || pipe->fd_output < 0)
		return (ft_write_err("Err: File doesn't exist."));
	i = 2;
	pipe->commands = malloc((argc - 1) * sizeof(char *));
	if (!pipe->commands)
		return (0);
	while (i < argc)
	{
		pipe->commands[i - 2] = argv[i];
		i++;
	}
	return (1);
}

/*
 * The pipex program ...
 */
int	main(int argc, char **args)
{
	t_pipex	pipe;
	int		res;

	if (argc < 5)
		return (ft_write_err("Err: Mising args"));
	res = pipe_setup(&pipe, args, (argc - 1));
	if (!res)
		return (0);
	return (0);
}
