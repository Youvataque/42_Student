/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:46:43 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/27 14:51:05 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// load img in memory 
void	load_images(t_game *game)
{
	game->way_img = mlx_xpm_file_to_image(game->mlx, "assets/way.xpm",
			&game->tile_size, &game->tile_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&game->tile_size, &game->tile_size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&game->tile_size, &game->tile_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&game->tile_size, &game->tile_size);
	game->colec_img = mlx_xpm_file_to_image(game->mlx, "assets/colec.xpm",
			&game->tile_size, &game->tile_size);
	if (!game->way_img || !game->wall_img || !game->player_img
		|| !game->exit_img || !game->colec_img)
	{
		ft_printf("Error: Failed to load one or more images\n");
		exit(1);
	}
}

/////////////////////////////////////////////////////////////////////////////
// close the windows and clean all img en memory
int	close_window(t_game *game)
{
	if (game->way_img)
		mlx_destroy_image(game->mlx, game->way_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->colec_img)
		mlx_destroy_image(game->mlx, game->colec_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_printf("Window closed.\n");
	exit(0);
	return (0);
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
}

/////////////////////////////////////////////////////////////////////////////
// start the game
void	start_all(char **map, t_game *game)
{
	int		x;
	int		y;
	int		size;

	size = game->tile_size;
	load_images(game);
	mlx_hook((*game).win, 17, 0, close_window, game);
	y = 0;
	while (y < (*game).height)
	{
		x = 0;
		while (x < (*game).width)
		{
			render_tile(game, x * size, y * size, map[y][x]);
			x++;
		}
		y++;
	}
	mlx_loop((*game).mlx);
}

/////////////////////////////////////////////////////////////////////////////
// create the window and load all
void	display_map(char **map)
{
	t_game	g;

	g.tile_size = 64;
	g.map = map;
	g.height = map_heigth(map);
	g.width = (int)ft_strlen(map[0]);
	g.mlx = mlx_init();
	if (!g.mlx)
	{
		ft_printf("Error: Failed to initialize MiniLibX\n");
		exit(1);
	}
	g.win = mlx_new_window(g.mlx, g.width * 64, g.height * 64, "so_long");
	if (!g.win)
	{
		ft_printf("Error: Failed to create window\n");
		exit(1);
	}
	start_all(map, &g);
}
