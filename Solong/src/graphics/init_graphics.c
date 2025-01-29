/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:46:43 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 12:45:59 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// load img in memory 
void	load_images(t_game *game)
{
	game->way_img = mlx_xpm_file_to_image(game->mlx, "assets/way.xpm",
			&game->size, &game->size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&game->size, &game->size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&game->size, &game->size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&game->size, &game->size);
	game->colec_img = mlx_xpm_file_to_image(game->mlx, "assets/colec.xpm",
			&game->size, &game->size);
	init_enemies(game);
	if (!game->way_img || !game->wall_img || !game->player_img
		|| !game->exit_img || !game->colec_img || !game->bad_img)
	{
		ft_printf("Error: Failed to load one or more images\n");
		exit(1);
	}
}

/////////////////////////////////////////////////////////////////////////////
// render good img from map chars
void	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->way_img, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->colec_img, x, y);
	else if (tile == 'B')
		mlx_put_image_to_window(game->mlx, game->win, game->bad_img, x, y);
}

/////////////////////////////////////////////////////////////////////////////
// render only visible tiles based on camera position
void	render_visible_map(t_game *game)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	t_point	windo;

	windo = game->windo;
	y = 0;
	while (y < windo.y)
	{
		x = 0;
		while (x < windo.x)
		{
			map_x = game->camera.x + x;
			map_y = game->camera.y + y;
			if (map_x >= 0 && map_x < game->width && map_y >= 0
				&& map_y < game->height)
				render_tile(game, x * game->size, y * game->size,
					game->map[map_y][map_x]);
			x++;
		}
		y++;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Start the game
void	start_all(t_game *game)
{
	game->max_c = get_nbc(game->map);
	game->inst_c = 0;
	load_images(game);
	mlx_hook(game->win, 17, 0, lose_game, game);
	mlx_key_hook(game->win, key_pressed, game);
	mlx_loop_hook(game->mlx, move_enemies, game);
	render_visible_map(game);
	display_counter(game);
	mlx_loop(game->mlx);
}

/////////////////////////////////////////////////////////////////////////////
// Create the window and load all
void	display_map(char **map)
{
	t_game	g;

	g.size = 64;
	g.map = map;
	g.height = map_heigth(map);
	g.width = (int)ft_strlen(map[0]);
	g.windo.x = ternary(g.width < 20, g.width, 20);
	g.windo.y = ternary(g.height < 15, g.height, 15);
	g.mlx = mlx_init();
	g.step = 0;
	g.camera = (t_point){0, 0};
	if (!g.mlx)
	{
		ft_printf("Error: Failed to initialize MiniLibX\n");
		exit(1);
	}
	g.win = mlx_new_window(g.mlx, g.windo.x * g.size,
			g.windo.y * g.size, "so_long");
	if (!g.win)
	{
		ft_printf("Error: Failed to create window\n");
		exit(1);
	}
	start_all(&g);
}
