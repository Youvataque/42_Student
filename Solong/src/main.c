/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:10 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/27 14:51:28 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac == 2)
	{
		map = init_map(av[1]);
		if (!check_all(map))
			return (1);
		display_map(map);
	}
	else
		ft_printf("Error\n");
	return (0);
}
