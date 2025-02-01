/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:23:17 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/01 15:55:22 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex(int in, int out, char **cmd, char **env)
{
	int		fd[2];
	pid_t	pid[2];

	if (pipe(fd) == -1)
		return (perror("pipe"), exit(1));
	pid[0] = fork();
	if (pid[0] == -1)
		return (perror("fork"), exit(1));
	if (pid[0] == 0)
	{
		close(fd[0]);
		ft_exec(cmd[0], in, fd[1], env);
	}
	pid[1] = fork();
	if (pid[1] == -1)
		return (perror("fork"), exit(1));
	if (pid[1] == 0)
	{
		close(fd[1]);
		ft_exec(cmd[1], fd[0], out, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	int	in;
	int	out;

	if (ac == 5)
	{
		in = open(av[1], O_RDONLY);
		out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		pipex(in, out, &(av[2]), env);
	}
	else
		return (ft_printf("Error\n"), 1);
}
