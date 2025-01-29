/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:31:23 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 13:56:16 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_counter(t_game *game)
{
	char	*step_str;
	char	*final_str;

	step_str = ft_itoa(game->step);
	final_str = ft_strjoin("Steps: ", step_str);
	mlx_string_put(game->mlx, game->win, 10, 20, 0x000000, final_str);
	free(step_str);
	free(final_str);
}

void	move_one(t_game *g, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	dir;
	int	new_x;
	int	new_y;

	dx[0] = 0;
	dx[1] = 0;
	dx[2] = -1;
	dx[3] = 1;
	dy[0] = -1;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = 0;
	dir = rand() % 4;
	new_x = x + dx[dir];
	new_y = y + dy[dir];
	if (ft_strchr("1CEBP", g->map[new_y][new_x]) == NULL)
	{
		g->map[y][x] = '0';
		g->map[new_y][new_x] = 'B';
	}
}

int	move_enemies(t_game *game)
{
	int			x;
	int			y;
	static int	timer = 0;

	y = 0;
	timer++;
	if (timer < 50000)
		return (0);
	timer = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if (game->map[y][x] == 'B')
				move_one(game, x, y);
			x++;
		}
		y++;
	}
	render_visible_map(game);
	display_counter(game);
	return (1);
}

void	init_enemies(t_game *game)
{
	int	i;
	int	j;
	int	enemy_count;
	int	max_enemies;

	enemy_count = 0;
	max_enemies = (game->width * game->height) / 50;
	game->bad_img = mlx_xpm_file_to_image(game->mlx, "assets/bad.xpm",
			&game->size, &game->size);
	if (!game->bad_img)
	{
		ft_printf("Error: Failed to load enemy image\n");
		exit(1);
	}
	srand(time(NULL));
	while (enemy_count < max_enemies)
	{
		i = rand() % game->height;
		j = rand() % game->width;
		if (game->map[i][j] == '0')
		{
			game->map[i][j] = 'B';
			enemy_count++;
		}
	}
}
