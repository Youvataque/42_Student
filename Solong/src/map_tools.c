/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:07:20 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/28 13:24:52 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// return the start position or an error less/more than 1
t_point	get_user_l(char **map, char c)
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
			if (map[nav.y][nav.x] == c)
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
// get number of collectible
int	get_nbc(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < map_heigth(map))
	{
		x = 0;
		while (x < (int)ft_strlen(map[y]))
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
