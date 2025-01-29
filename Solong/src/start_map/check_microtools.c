/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_microtools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:02:16 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 14:42:16 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// return the heigth of map (for ["111", "101", "111"] it's 3). 
// This function issimilare to map_lines with diff args
int	map_heigth(char **map)
{
	int	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

/////////////////////////////////////////////////////////////////////////////
// check if the first and last lines are only composed of '1'
int	check_lines(char **map)
{
	size_t	last;
	size_t	x;

	x = 0;
	last = map_heigth(map) - 1;
	while (x < ft_strlen(map[0]))
	{
		if (map[0][x] != '1' || map[last][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

/////////////////////////////////////////////////////////////////////////////
// check if the first and the last columns are only composed of '1'
int	check_col(char **map)
{
	int	last;
	int	x;

	x = 0;
	last = ft_strlen(map[0]) - 1;
	while (x < (map_heigth(map)))
	{
		if (map[x][0] != '1' || map[x][last] != '1')
			return (0);
		x++;
	}
	return (1);
}

/////////////////////////////////////////////////////////////////////////////
// fill function (like flood_fill) for know if all position are accessible
void	fill(char **map, t_point begin, t_point max, char *charset)
{
	if (begin.x >= max.x || begin.y >= max.y || begin.x < 0 || begin.y < 0
		|| ft_strchr(charset, map[begin.y][begin.x]) == NULL)
		return ;
	map[begin.y][begin.x] = 'X';
	fill(map, (t_point){begin.x - 1, begin.y}, max, charset);
	fill(map, (t_point){begin.x + 1, begin.y}, max, charset);
	fill(map, (t_point){begin.x, begin.y - 1}, max, charset);
	fill(map, (t_point){begin.x, begin.y + 1}, max, charset);
}

/////////////////////////////////////////////////////////////////////////////
// clone a map
char	**clone_map(char **map)
{
	int		x;
	int		heigth;
	char	**result;

	heigth = map_heigth(map);
	x = 0;
	result = malloc(sizeof(char *) * (heigth + 1));
	if (!result)
		return (NULL);
	while (x < heigth)
	{
		result[x] = ft_strdup(map[x]);
		x++;
	}
	result[x] = NULL;
	return (result);
}
