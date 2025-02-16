/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:36:23 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/15 17:46:57 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*exec_phi(void *arg)
{
	t_phidat	*phidat;
	pthread_t	check;

	phidat = (t_phidat *)arg;
	if (phidat->philos->id % 2 == 0)
    	ft_usleep(phidat->datas->t_eat / 10);
	while (!ended(phidat->datas, 0) && 
		!is_finished(phidat->philos, phidat->datas))
	{
		pthread_create(&check, NULL, check_death, phidat);
		take_fork(phidat->philos, phidat->datas);
		eat(phidat->philos, phidat->datas);
		p_sleep(phidat->philos, phidat->datas);
		think(phidat->philos, phidat->datas);
		pthread_detach(check);
	}
	return (NULL);
}

void	philosophers(t_pdatas *datas, t_philo *philos)
{
	int			i;
	t_phidat	*phidat;

	i = 0;
	while (i < datas->nb_p)
	{
		phidat = malloc(sizeof(t_phidat));
		if (!phidat)
			return ;
		phidat->philos = &philos[i];
		phidat->datas = datas;
		pthread_create(&philos[i].thread, NULL, exec_phi, (void *)phidat);
		i++;
	}
	i = -1;
	while (++i < datas->nb_p)
		if (pthread_join(philos[i].thread, NULL) != 0)
			return ;
}

int	main(int ac, char **av)
{
	t_pdatas	datas;
	t_philo		*philos;

	if (ac >= 5 && ac < 7)
	{
		datas.nb_p = ft_atoi(av[1]);
		datas.t_die = ft_atoi(av[2]);
		datas.t_eat = ft_atoi(av[3]);
		datas.t_sleep = ft_atoi(av[4]);
		datas.t_start = get_time();
		datas.end = 0;
		pthread_mutex_init(&(datas.write_mutex), NULL);
		pthread_mutex_init(&(datas.end_mutex), NULL);
		philos = init_structs(datas.nb_p, datas);
		datas.max_meal = -1;
		if (ac == 6)
			datas.max_meal = ft_atoi(av[5]);
		philosophers(&datas, philos);
	}
	else
		return (printf("Error wrong args\n"), 1);
	return (0);
}
