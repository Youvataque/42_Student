/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:36:23 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/07 13:31:59 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philoso(t_philo datas)
{

}

int main(int ac, char **av)
{
	t_philo datas;

	if (ac >= 5)
	{
		datas.nb_p = ft_atoi(av[1]);
		datas.t_die = ft_atoi(av[2]);
		datas.t_eat = ft_atoi(av[3]);
		datas.t_sleep = ft_atoi(av[4]);
		if (ac == 6) {
			datas.max_eat = ft_atoi(av[5]);
		}
		philoso(datas);
	}
	else
		return (printf("Error wrong args\n"), 1);
}
