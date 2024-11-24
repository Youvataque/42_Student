/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:42 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/24 15:50:09 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	char		*result;
	char		*temp;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	count = read(fd, buffer, BUFFER_SIZE);
	while (count > 0)
	{
		buffer[count] = '\0';
		if (!line)
			line = ft_strdup("");
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
		if ((newline = ft_strchr(line, '\n')))
		{
			result = ft_substr(line, 0, newline - line + 1);
			temp = ft_strdup(newline + 1);
			free(line);
			line = temp;
			return (result);
		}
		count = read(fd, buffer, BUFFER_SIZE);
	}
	if (line && *line)
	{
		result = ft_strdup(line);
		free(line);
		line = NULL;
		return (result);
	}

	free(line);
	line = NULL;
	return (NULL);
}

