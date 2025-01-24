/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:18:25 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/24 14:21:28 by yseguin          ###   ########.fr       */
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

/* structs */
typedef struct s_point {
	int	x;
	int	y;
} t_point;

/* components */
void	fill(char **map, t_point begin, t_point max, char *charset);
void	cleanMap(char **map);
t_point	get_user_p(char **map);
char	**init_map(const char *path);
char	**clone_map(char **map);
size_t	check_format(char **map);
int		map_heigth(char **map);
int		check_lines(char **map);
int		check_col(char **map);
int		check_all(char **map);
#endif