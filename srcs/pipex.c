/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/05 20:58:59 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
 * The pipex program ...
 */
int	main(int argc, char **argv)
{
	int		i;
	t_pipex	pipe;

	argc = argc - 1;
	if (argc < 4)
		return (ft_write_err("Err: Mising args"));
	pipe.fd_input = ft_open(argv[1]);
	pipe.fd_output = ft_open(argv[argc]);
	if (pipe.fd_input < 0 || pipe.fd_output < 0)
		return (ft_write_err("Err: File doesn't exist."));
	i = 2;
	while (i < argc)
	{
		printf("Arg: %s \n", argv[i]);
		i++;
	}
	return (0);
}
