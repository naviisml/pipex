/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/08 16:55:03 by nismail       ########   odam.nl         */
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
	if (err == -1)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": command doesn't exist.\n", STDERR_FILENO);
		exit(127);
	}
}

/**
 * The process_run() function ...
 */
void	process_run(t_pipex *pipex)
{
	int		pid;

	dup2(pipex->fd_input, STDIN_FILENO);
	dup2(pipex->fd_output, STDOUT_FILENO);
	pipe(pipex->pipes);
	pid = fork();
	if (pid)
	{
		close(pipex->pipes[1]);
		dup2(pipex->pipes[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipex->pipes[0]);
		dup2(pipex->pipes[1], STDOUT_FILENO);
		if (pipex->fd_input == STDIN_FILENO)
			exit(1);
		else
			process_exec(pipex, 0);
	}
	process_exec(pipex, 1);
}
