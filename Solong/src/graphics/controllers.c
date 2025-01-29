/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:53:48 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 15:33:42 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// Update camera position based on player position
void	update_camera(t_game *game, t_point player_pos)
{
	t_point	windo;

	windo = game->windo;
	if (!game)
		return ;
	if (game->windo.x <= 0 || game->windo.y <= 0)
		return ;
	if (player_pos.x < 0 || player_pos.x >= game->width
		|| player_pos.y < 0 || player_pos.y >= game->height)
		return ;
	game->camera.x = player_pos.x - windo.x / 2;
	game->camera.y = player_pos.y - windo.y / 2;
	if (game->camera.x < 0)
		game->camera.x = 0;
	if (game->camera.y < 0)
		game->camera.y = 0;
	if (game->camera.x > game->width - windo.x)
		game->camera.x = game->width - windo.x;
	if (game->camera.y > game->height - windo.y)
		game->camera.y = game->height - windo.y;
}

/////////////////////////////////////////////////////////////////////////////
// close the windows and clean all img in memory
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
	if (game->bad_img)
		mlx_destroy_image(game->mlx, game->bad_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	lose_game(t_game *game)
{
	ft_printf("You lose the game!\n");
	clean_map(game->map);
	close_window(game);
	return (0);
}

/////////////////////////////////////////////////////////////////////////////
// Move the player and update camera
void	moove(t_game *game, t_point old, t_point new)
{
	if (new.x < 0 || new.x >= game->width || new.y < 0 || new.y >= game->height
		|| game->map[new.y][new.x] == '1'
		|| (game->map[new.y][new.x] == 'E' && game->inst_c != game->max_c))
		return ;
	if (game->map[new.y][new.x] == 'B')
	{
		lose_game(game);
		return ;
	}
	if (game->map[new.y][new.x] == 'C')
		game->inst_c++;
	game->step++;
	ft_printf("number of step : %d\n", game->step);
	if (game->map[new.y][new.x] == 'E')
	{
		ft_printf("Congratulation ! You won.");
		clean_map(game->map);
		close_window(game);
	}
	game->map[new.y][new.x] = 'P';
	game->map[old.y][old.x] = '0';
	update_camera(game, new);
	render_visible_map(game);
	display_counter(game);
}

/////////////////////////////////////////////////////////////////////////////
// do the good action for a pressed key
int	key_pressed(int keycode, void *param)
{
	t_point	old;

	old = get_user_l(((t_game *)param)->map, 'P');
	if (keycode == KEY_ESC)
		lose_game((t_game *)param);
	else if (keycode == KEY_W)
		moove((t_game *)param, old, (t_point){old.x, old.y - 1});
	else if (keycode == KEY_S)
		moove((t_game *)param, old, (t_point){old.x, old.y + 1});
	else if (keycode == KEY_A)
		moove((t_game *)param, old, (t_point){old.x - 1, old.y});
	else if (keycode == KEY_D)
		moove((t_game *)param, old, (t_point){old.x + 1, old.y});
	return (0);
}
