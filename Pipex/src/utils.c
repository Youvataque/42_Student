/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:56 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/03 12:41:28 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

///////////////////////////////////////////////////////////////////////////////
// Function for search the cmd path (ex : usr/bin)
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

///////////////////////////////////////////////////////////////////////////////
// function for clean an str map
void	clean_tab(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

///////////////////////////////////////////////////////////////////////////////
// function for check if the cmd is usable or not
int	check_cmd(char *cmd, char **env)
{
	char	**map;
	char	*path;

	map = ft_split(cmd, ' ');
	path = search_path(map[0], env);
	if (!path || *path == '\0')
		return (clean_tab(map), free(path), 0);
	else
		return (clean_tab(map), free(path), 1);
}

///////////////////////////////////////////////////////////////////////////////
// function for execute the cmd in a selected fd from a selected fd
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
	clean_tab(args);
	exit(1);
}

///////////////////////////////////////////////////////////////////////////////
// Execute the good ft_exec in pipex (split for norm...)
void	pipex_exec(t_pipevar vars, int io[2], char **env, int nb_arg)
{
	if (vars.prev != io[0])
		close(io[0]);
	if (vars.i < (nb_arg - 1))
		close(vars.fd[0]);
	if (vars.i == nb_arg - 1)
		ft_exec(vars.cmds[vars.i], vars.prev, io[1], env);
	else
		ft_exec(vars.cmds[vars.i], vars.prev, vars.fd[1], env);
}
