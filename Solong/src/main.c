/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:10 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/29 11:11:15 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/////////////////////////////////////////////////////////////////////////////
// print the good error
void	type_error(int error)
{
	if (error == 0)
		ft_printf("The map is not corretly generated !\n");
	else if (error == 2)
		ft_printf("All lines are not equals !\n");
	else if (error == 3)
		ft_printf("The map is not rectangular !\n");
	else if (error == 4)
		ft_printf("The map is not properly closed !\n");
	else if (error == 5)
		ft_printf("There is not or more than one exit/begin !\n");
	else if (error == 6)
		ft_printf("The collectible are not accessible !\n");
}

/////////////////////////////////////////////////////////////////////////////
// main of software
int	main(int ac, char **av)
{
	char	**map;
	int		error;

	if (ac == 2)
	{
		map = init_map(av[1]);
		error = check_all(map);
		if (error != 1)
		{
			ft_printf("Error\n");
			type_error(error);
			clean_map(map);
			return (1);
		}
		display_map(map);
		clean_map(map);
	}
	else
		ft_printf("Error\n");
	return (0);
}
