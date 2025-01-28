/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:53:48 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/28 09:07:06 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	moove(t_game *game, t_point old, t_point new)
{
	if (old.x == -1 || old.y == -1 || game->map[new.y][new.x] == '1')
		return ;
	else
	{
		if (game->map[new.y][new.x] == 'C')
			game->step++;
		game->map[new.y][new.x] = 'P';
		game->map[old.y][old.x] = '0';
		render_tile(game, old.x * 64, old.y * 64, '0');
		render_tile(game, new.x * game->size, new.y * game->size, 'P');
	}
}

int	key_pressed(int keycode, void *param)
{
	t_point	old;

	old = get_user_l(((t_game *)param)->map, 'P');
	if (keycode == KEY_ESC)
		close_window((t_game *)param);
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
