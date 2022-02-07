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
 * 
 * Step 1. Execute command in execve
 * Step 2. Save the output to the struct
 * Step 3. Use the output on the next command
 * ...
 * Step 4. When this is done, save the output to the outputFile
 */
static void	process_exec(t_pipex *pipex, char **args)
{
	int		err;
	char	*cmd;

	dup2(pipex->pipes[1], STDOUT_FILENO);
	cmd = env_cmd(pipex, args[0]);
	err = execve(cmd, args, pipex->env);
	if (err == -1)
		perror(args[0]);
}

/*
 * The process_start() function executes the command determined by
 * char *cmd, then catches and returns the stdout of that command.
 */
int	process_start(t_pipex *pipex, int id)
{
	int		pid;
	char	**args;

	pipe(pipex->pipes);
	pid = fork();
	if (pid == 0)
	{
		args = ft_split(pipex->cmds[id], ' ');
		process_exec(pipex, args);
		exit(pid);
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		;
	return (1);
}
