/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:07:37 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/12/03 14:27:21 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int		fd[2];
	int		open;
	int		i;
	pid_t	pid;

	i = -1;
	open = 0;
	while (cmds[++i])
	{
		if (cmds[i + 1]) //if theres more than one command, open pipes
		{
			if (pipe(fd) < 0)
				return (1);
		}
		pid = fork();
		if (pid < 0) //if forking failed, close pipes and exit
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
				return (1);
			}
		}
		if (pid == 0) //we are in child
		{
			if (open) //if open is not 0, we are not in the first command
			{
				if (dup2(open, STDIN_FILENO) < 0)
					exit(1);
				close(open);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) < 0)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (open)
			close(open);
		if (cmds[i + 1])
			open = fd[0];
		else
		{
			open = 0;
			close(fd[0]);
		}
		close(fd[1]);
	}
	while (1)
	{
		if (wait(NULL) <= 0)
			break ;
	}
	return (0);
}

#include <stdio.h>

int main()
{
    // Define a few sample commands to pass to picoshell
    // Example: `ls -l | grep 'test' | wc -l`
    
    char *cmd1[] = {"ls", "-l", NULL};  // First command: ls -l
    char *cmd2[] = {"grep", "test", NULL}; // Second command: grep test
    char *cmd3[] = {"wc", "-l", NULL};   // Third command: wc -l

    // Create an array of command arrays
    char **cmds[] = {cmd1, cmd2, cmd3, NULL}; // NULL marks the end of commands
    
    // Call picoshell with the array of commands
    if (picoshell(cmds) == 0)
	{
        printf("Commands executed successfully.\n");
    } 
	else
	{
        printf("An error occurred while executing the commands.\n");
    }
    return 0;
}
