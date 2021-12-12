/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2021/12/12 17:40:31 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

/*
 * The debug_pipex_struct() function ...
 */
void	debug_pipex_struct(t_pipex *pipe)
{
	int	i;

	printf("Input: %d \n", pipe->fd_input);
	printf("Output: %d \n", pipe->fd_output);
	i = 0;
	while (i < pipe->cmdc)
	{
		printf("Command %d: %s \n", (i + 1), pipe->cmds[i]);
		i++;
	}
}