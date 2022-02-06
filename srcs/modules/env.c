/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 19:16:38 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/*
 * The env_parse() function loops through the program's enviourment variables
 * and saves the `PATH` variable to t_pipex *pipex->path
 */
void	env_parse(t_pipex *pipex)
{
	while (ft_strncmp("PATH", *pipex->env, 4))
	{
		pipex->env++;
	}
	pipex->path = (*pipex->env + 5);
}

	ft_putchar_fd('\n', 2);
	ft_putstr_fd(bin, 2);
	ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
	return (bin);
}
