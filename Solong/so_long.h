/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:18:25 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/22 16:12:24 by yseguin          ###   ########.fr       */
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

#endif