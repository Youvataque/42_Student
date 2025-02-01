/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:56 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/01 15:54:52 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*search_path(char *cmd, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	*result;

	if (pipe(fd) == -1)
		return (perror("pipe"), NULL);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), NULL);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/which", (char *[]){"which", cmd, NULL}, env);
		exit(1);
	}
	close(fd[1]);
	result = get_next_line(fd[0]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	return (result);
}

void	ft_exec(char *cmd, int infd, int outfd, char **env)
{
	char	*cmd_path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("ft_split");
		exit(1);
	}
	cmd_path = search_path(args[0], env);
	cmd_path[ft_strlen(cmd_path) - 1] = '\0';
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	execve(cmd_path, args, env);
	perror("execve");
	free(cmd_path);
	free(args);
	exit(1);
}
