/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:46:10 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 15:37:22 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// count number of lines in the text.
int	map_lines(const char *path)
{
	int		result;
	char	*temp;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	temp = get_next_line(fd);
	result = 0;
	while (temp)
	{
		result++;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (result);
}

/////////////////////////////////////////////////////////////////////////////
// initialise a map from txt file using getNextLine. Format : ->
// ["111", "101", "111"]
char	**init_map(const char *path)
{
	int		fd;
	int		index;
	char	*temp;
	char	**result;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (map_lines(path) == 0 || map_lines(path) == -1)
		return (NULL);
	result = malloc(sizeof(char *) * (map_lines(path) + 1));
	temp = get_next_line(fd);
	index = 0;
	while (temp)
	{
		if (ft_strlen(temp) == 0)
			return (free(temp), NULL);
		if (temp[ft_strlen(temp) - 1] == '\n')
			temp[ft_strlen(temp) - 1] = '\0';
		result[index++] = temp;
		temp = get_next_line(fd);
	}
	result[index] = NULL;
	close(fd);
	return (result);
}

/////////////////////////////////////////////////////////////////////////////
// clean a map after usage
void	clean_map(char **map)
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
