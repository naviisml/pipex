/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/05 21:07:37 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
 * The pipe_setup() function ...
 */
static int	pipe_setup(t_pipex *pipe, char **argv, int argc)
{
	int		i;

	pipe->fd_input = ft_open(argv[1]);
	pipe->fd_output = ft_open(argv[argc]);
	if (pipe->fd_input < 0 || pipe->fd_output < 0)
		return (ft_write_err("Err: File doesn't exist."));
	i = 2;
	while (i < argc)
	{
		printf("Arg: %s \n", argv[i]);
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
