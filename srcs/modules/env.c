/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/07 12:40:54 by nismail       ########   odam.nl         */
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
	if (ft_chrncmp(cmd, '/', 1) != 0)
		cmd = ft_strjoin("/", cmd);
	if (!cmd)
		exit(-1);
	while (paths[i])
	{
		bin = ft_strjoin(paths[i], cmd);
		if (!bin)
			exit(-1);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		i++;
	}
	return (0);
}
