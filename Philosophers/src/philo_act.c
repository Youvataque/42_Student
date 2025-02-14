/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:02:37 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/14 19:07:59 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void print(t_pdatas* datas, t_philo *philo, char *str)
{
	long int time;

	pthread_mutex_lock(&(datas->write_mutex));
	time = get_time() - datas->t_start;
	pthread_mutex_lock(&(datas->end_mutex));
	if (!datas->end && time >= 0 && time <= INT_MAX)
	{
		pthread_mutex_unlock(&(datas->end_mutex));
		printf("%ld - %d - %s\n", get_time() - datas->t_start, philo->id, str);
	}
	else
	{
		pthread_mutex_unlock(&(datas->end_mutex));
	}
	pthread_mutex_unlock(&(datas->write_mutex));
}

int	is_finished(t_philo *philo, t_pdatas *datas)
{
	if (datas->max_meal != -1)
	{
		if (datas->max_meal == philo->c_meal)
			return (1);
	}
	return (0);
}

int	is_dead(t_philo *philo, t_pdatas *datas)
{
	pthread_mutex_lock(&(philo->meal_mutex));
	if (get_time() - philo->t_meal >= datas->t_die)
		return (pthread_mutex_unlock(&(philo->meal_mutex)), 1);
	return (pthread_mutex_unlock(&(philo->meal_mutex)), 0);
}

int	ended(t_pdatas *datas, int update)
{
	pthread_mutex_lock(&(datas->end_mutex));
	if (update)
		datas->end = 1;
	if (datas->end)
		return (pthread_mutex_unlock(&(datas->end_mutex)), 1);
	return (pthread_mutex_unlock(&(datas->end_mutex)), 0);
}

void	*check_death(void *arg)
{
	t_phidat *phidat;

	phidat = (t_phidat *)arg;
	while (!ended(phidat->datas, 0))
	{
		if (is_finished(phidat->philos, phidat->datas))
            return NULL;
		if (is_dead(phidat->philos, phidat->datas))
		{
			print(phidat->datas, phidat->philos, "died");
			ended(phidat->datas, 1);
			break;
		}
		usleep(500);
	}
	return (NULL);
}

void	take_fork(t_philo *philo, t_pdatas *datas)
{
	pthread_mutex_lock(&(philo->leftf->mutex));
	print(datas, philo, "take l🍴");
	if (datas->nb_p == 1)
		return(usleep(datas->t_die * 1000), (void)0);
	pthread_mutex_lock(&(philo->rightf->mutex));
	print(datas, philo, "take r🍴");
}

void	eat(t_philo *philo, t_pdatas *datas)
{
	print(datas, philo, "eat 🍽️");
	philo->t_meal = get_time();
	usleep(datas->t_eat * 1000);
	pthread_mutex_unlock(&(philo->rightf->mutex));
	pthread_mutex_unlock(&(philo->leftf->mutex));
	(philo->c_meal) += 1;
	usleep(200);
}

void	p_sleep(t_philo *philo, t_pdatas *datas)
{
	print(datas, philo, "sleep 😴");
	usleep(datas->t_sleep * 1000);
}

void	think(t_philo *philo, t_pdatas *datas)
{
	print(datas, philo, "think 💭");
}