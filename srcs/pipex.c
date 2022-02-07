/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/07 12:43:03 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
 * The pipex program ...
 */
int	main(int argc, char **args, char **env)
{
	t_pipex	pipex;
	int		res;

	if (argc != 5)
		return (ft_write_err("Err: Missing arguments"));
	res = pipe_initialize(&pipex, args, (argc - 1), env);
	if (!res)
		return (0);
	env_parse(&pipex);
	pipe_close(&pipex);
	return (1);
}
