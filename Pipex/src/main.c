/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:23:17 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/03 12:41:27 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

///////////////////////////////////////////////////////////////////////////////
// Function pipex, similare to systeme cmd : in < cmd1 | cmd2  ... | cmdn > out
void	pipex(int io[2], int nb_arg, char **env, char **cmds)
{
	t_pipevar	vars;

	vars.i = 0;
	vars.prev = io[0];
	vars.cmds = cmds;
	while (vars.i < nb_arg)
	{
		if (vars.i < (nb_arg - 1) && pipe(vars.fd) == -1)
			return (perror("pipe"), exit(1));
		vars.pid = fork();
		if (vars.pid == -1)
			return (perror("fork"), exit(1));
		if (vars.pid == 0)
			pipex_exec(vars, io, env, nb_arg);
		close(vars.prev);
		if (vars.i < (nb_arg - 1))
		{
			close(vars.fd[1]);
			vars.prev = vars.fd[0];
		}
		(vars.i)++;
	}
	while (wait(NULL) > 0)
		;
}

///////////////////////////////////////////////////////////////////////////////
// Main of the software
int	main(int ac, char **av, char **env)
{
	int	in;
	int	out;
	int	i;

	i = 2;
	if (ac >= 5)
	{
		in = open(av[1], O_RDONLY);
		if (in == -1)
			return (ft_printf("No such file or directory\n"), 1);
		while (i < ac - 1)
		{
			if (!check_cmd(av[i], env))
				return (ft_printf("%s : command not found\n", av[i]), 1);
			i++;
		}
		out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		pipex((int [2]){in, out}, ac - 3, env, &(av[2]));
	}
	else
		return (ft_printf("Error\n"), 1);
}
