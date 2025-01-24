/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:10 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/24 14:23:18 by yseguin          ###   ########.fr       */
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
		ft_printf("%d", check_all(map));
	}
	else
		ft_printf("Error\n");
	return (0);
}
