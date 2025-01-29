/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:48:05 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 14:33:36 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// check if all map lines has the same length
size_t	check_format(char **map)
{
	int		x;
	size_t	len;

	x = 0;
	len = ft_strlen(map[0]);
	while (map[x])
	{
		if (ft_strlen(map[x]) != len)
			return (0);
		x++;
	}
	return (1);
}

/////////////////////////////////////////////////////////////////////////////
// check if the map is rectangular
int	check_form(char **map)
{
	size_t	width;
	size_t	heigth;

	heigth = 0;
	width = ft_strlen(map[0]);
	while (map[heigth])
		heigth++;
	if (heigth == width)
		return (0);
	return (1);
}

/////////////////////////////////////////////////////////////////////////////
// check if the map is properly closed
int	check_closed(char **map)
{
	if (map_heigth(map) < 3)
		return (0);
	if (ft_strlen(map[0]) < 3)
		return (0);
	return (check_lines(map) && check_col(map));
}

/////////////////////////////////////////////////////////////////////////////
// check if the exit and collectible are accessible
int	check_conformity(char **map, t_point p, char *access, char *isIn)
{
	char	**temp;
	t_point	max;
	t_point	nav;

	nav = (t_point){0, 0};
	max = (t_point){ft_strlen(map[0]), map_heigth(map)};
	temp = clone_map(map);
	fill(temp, p, max, access);
	while (nav.x < max.x)
	{
		while (nav.y < max.y)
		{
			if (ft_strchr(isIn, temp[nav.y][nav.x]) == NULL)
				return (clean_map(temp), 0);
			(nav.y)++;
		}
		nav.y = 0;
		(nav.x)++;
	}
	clean_map(temp);
	return (1);
}

/////////////////////////////////////////////////////////////////////////////
// start all check
int	check_all(char **map)
{
	t_point	p;
	t_point	e;

	if (!map || !map[0])
		return (0);
	if (!check_format(map))
		return (2);
	if (!check_form(map))
		return (3);
	if (!check_closed(map))
		return (4);
	p = get_user_l(map, 'P');
	if (p.x == -1 || p.y == -1)
		return (5);
	e = get_user_l(map, 'E');
	if (e.x == -1 && e.y == -1)
		return (5);
	if (!check_conformity(map, p, "0CEP", "1X"))
		return (6);
	if (!check_conformity(map, p, "0CP", "1XE"))
		return (6);
	return (1);
}
