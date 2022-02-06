/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 16:47:57 by nismail       ########   odam.nl         */
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

	input = dup2(pipe->fd_input, STDIN_FILENO);
	output = dup2(pipe->fd_output, STDOUT_FILENO);
	err = execve("/bin/ls", args, pipe->env);
	if (err == -1)
		perror(args[0]);
}

/*
 * The process_start() function executes the command determined by
 * char *cmd, then catches and returns the stdout of that command.
 */
int	process_start(char *cmd, char **env)
{
	int	pid;
	char	**args;
	int		res;

	pid = fork();
	if (pid == 0)
	{
		args = ft_split(cmd, ' ');
		res = execve("/bin/sh", args, env);
		if (res == -1)
			ft_putstr_fd("Error\n", 1);
		exit(pid);
	}
	while (wait(NULL) != -1 || errno != ECHILD);
	return (1);
}
