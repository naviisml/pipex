/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 19:10:18 by nismail       ########   odam.nl         */
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
static void	process_exec(t_pipex *pipe, char **args)
{
	int		output;
	int		input;
	int		err;
	char	*cmd;

	input = dup2(pipe->fd_input, STDIN_FILENO);
	output = dup2(pipe->fd_output, STDOUT_FILENO);
	cmd = env_cmd(pipe, args[0]);
	err = execve(cmd, (args + 1), pipe->env);
	if (err == -1)
		perror(args[0]);
}

/*
 * The process_start() function executes the command determined by
 * char *cmd, then catches and returns the stdout of that command.
 */
int	process_start(t_pipex *pipe, int id)
{
	int		pid;
	char	**args;

	pid = fork();
	if (pid == 0)
	{
		args = ft_split(pipe->cmds[id], ' ');
		process_exec(pipe, args);
		exit(pid);
	}
	while (wait(NULL) != -1 || errno != ECHILD);
	return (1);
}
