/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:08:38 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/15 17:27:16 by yseguin          ###   ########.fr       */
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
	long diff;

	pthread_mutex_lock(&(philo->meal_mutex));
	diff = get_time() - philo->t_meal;
	pthread_mutex_unlock(&(philo->meal_mutex));
	return (diff >= datas->t_die);
}

int	ended(t_pdatas *datas, int update)
{
	int result;

	pthread_mutex_lock(&(datas->end_mutex));
	if (update)
		datas->end = 1;
	result = datas->end;
	pthread_mutex_unlock(&(datas->end_mutex));
	return (result);
}