/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/07 11:28:50 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * The process_exec() function ...
 */
static void	process_exec(t_pipex *pipex, int id)
{
	int		err;
	char	*cmd;
	char	**args;

	args = ft_split(pipex->cmds[id], ' ');
	cmd = env_cmd(pipex, args[0]);
	if (cmd == 0)
		cmd = pipex->cmds[0];
	err = execve(cmd, args, pipex->env);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command doesn't exist.\n", STDERR_FILENO);
	exit(127);
}

 */
{
	int		pid;

	pipe(pipex->pipes);
	pid = fork();
	{
	}
}
