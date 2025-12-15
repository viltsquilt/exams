/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:30:34 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/12/03 14:55:15 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_popen(const char *file, char *const av[], int type)
{
	pid_t	pid;
	int		fd[2];

	if (!file || !av || type != 'w' && type != 'r')
		return (-1);
	if (pipe(fd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				exit(-1);
		}
		else
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) < 0)
				exit(-1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, av);
		exit(-1);
	}
	if (type == 'r')
	{
		close(fd[1])
		return (fd[0]);
	}
	else
	{
		close(fd[0]);
		return (fd[1]);
	}
}
