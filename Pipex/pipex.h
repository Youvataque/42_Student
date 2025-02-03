/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:42:13 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/03 12:41:25 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "MyLibft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct s_pipevar
{
	int		fd[2];
	int		prev;
	int		i;
	char	**cmds;
	pid_t	pid;
}	t_pipevar;

void	ft_exec(char *cmd, int infd, int outfd, char **env);
void	pipex_exec(t_pipevar vars, int io[2], char **env, int nb_arg);
char	*search_path(char *cmd, char **env);
int		check_cmd(char *cmd1, char **env);

#endif