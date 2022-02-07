/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/07 11:16:52 by nismail       ########   odam.nl         */
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

/*
 * The env_parse() function loops over the pipex->path, and checks if the bin
 * exists.
 */
char	*env_cmd(t_pipex *pipex, char *cmd)
{
	char	**paths;
	int		i;
	char	*bin;

	paths = ft_split(pipex->path, ':');
	i = 0;
	while (paths[i])
	{
		bin = ft_strjoin(paths[i], ft_strjoin("/", cmd));
		if (access(bin, F_OK) == 0)
			break ;
		i++;
	}
	return (bin);
}
