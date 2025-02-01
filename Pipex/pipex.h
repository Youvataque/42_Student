/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:42:13 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/01 15:56:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "MyLibft/libft.h"
# include <stdio.h>

void	ft_exec(char *cmd, int infd, int outfd, char **env);
char	*search_path(char *cmd, char **env);

#endif