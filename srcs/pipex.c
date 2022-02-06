/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 19:07:14 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
 * The pipex program ...
 */
int	main(int argc, char **args, char **env)
{
	t_pipex	pipe;
	int		res;

	if (BONUS == 0 && argc != 5)
		return (ft_write_err("Err: Too many arguments"));
	if (argc < 5)
		return (ft_write_err("Err: Missing arguments"));
	res = pipe_initialize(&pipe, args, (argc - 1), env);
	if (!res)
		return (0);
	env_parse(&pipe);
	pipe_run(&pipe);
	pipe_close(&pipe);
	return (0);
}
