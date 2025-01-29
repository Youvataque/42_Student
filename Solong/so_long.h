/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:18:25 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 12:45:43 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MyLibft/libft.h"
# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

# include "minilibx-linux/mlx.h"

/* macros */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/* structs */
typedef struct s_point {
	int	x;
	int	y;
} t_point;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*way_img;
	void	*wall_img;
	void	*exit_img;
	void	*player_img;
	void	*colec_img;
	void	*bad_img;
	int		size;
	int		width;
	int		height;
	int		step;
	int		max_c;
	int		inst_c;
	t_point	windo;
	char	**map;
	t_point camera;
}	t_game;

/* components */
void	display_map(char **map);
void	display_counter(t_game *game);
int   move_enemies(t_game *game);
void    init_enemies(t_game *game);
void	fill(char **map, t_point begin, t_point max, char *charset);
void	render_tile(t_game *game, int x, int y, char tile);
void    render_visible_map(t_game *game);
void	clean_map(char **map);
t_point	get_user_l(char **map, char c);
char	**init_map(const char *path);
char	**clone_map(char **map);
size_t	check_format(char **map);
int		get_nbc(char **map);
int		lose_game(t_game *game);
int		map_heigth(char **map);
int		key_pressed(int keycode, void *param);
int		check_lines(char **map);
int		check_col(char **map);
int		check_all(char **map);
int		ternary(int condi, int one, int two);
#endif