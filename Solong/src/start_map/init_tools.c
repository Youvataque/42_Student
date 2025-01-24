/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:46:10 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/24 14:24:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// count number of lines in the text.
int	map_lines(const char *path)
{
	int		result;
	int		readed;
	char	temp[6];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("Erreur lors de l'ouverture du fichier"), -1);
	readed = read(fd, temp, 5);
	result = 0;
	while (readed > 0)
	{
		temp[5] = '\0';
		if (ft_strchr(temp, '\n') != NULL)
			result += 1;
		readed = read(fd, temp, 5);
	}
	if (readed < 0)
		return (perror("Erreur lors de la lecture du fichier"), close(fd), -1);
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
		return (perror("Erreur lors de l'ouverture du fichier"), NULL);
	result = malloc(sizeof(char *) * (map_lines(path) + 1));
	temp = get_next_line(fd);
	index = 0;
	while (temp)
	{
		if (temp[ft_strlen(temp) - 1] == '\n')
			temp[ft_strlen(temp) - 1] = '\0';
		result[index] = temp;
		index++;
		temp = get_next_line(fd);
	}
	result[index] = NULL;
	return (result);
}

/////////////////////////////////////////////////////////////////////////////
// return the start position or an error less/more than 1
t_point	get_user_p(char **map)
{
	t_point	nav;
	t_point	result;
	int		find;

	nav = (t_point){0, 0};
	result = (t_point){-1, -1};
	find = 0;
	while (nav.y < map_heigth(map))
	{
		while (nav.x < (int)ft_strlen(map[nav.y]))
		{
			if (map[nav.y][nav.x] == 'P')
			{
				if (++find > 1)
					return ((t_point){-1, -1});
				result = nav;
			}
			(nav.x)++;
		}
		nav.x = 0;
		(nav.y)++;
	}
	if (find == 1)
		return (result);
	return ((t_point){-1, -1});
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
