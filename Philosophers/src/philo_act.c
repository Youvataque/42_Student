/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:02:37 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/18 00:21:53 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check_death(void *arg)
{
	t_phidat *phidat;

	phidat = (t_phidat *)arg;
	ft_usleep(phidat->datas->t_die + 1);
	if (!ended(phidat->datas, 0))
	{
		if (is_finished(phidat->philos, phidat->datas))
            return (NULL);
		if (is_dead(phidat->philos, phidat->datas))
		{
			print(phidat->datas, phidat->philos, "died");
			ended(phidat->datas, 1);
		}
	}
	return (NULL);
}

void	take_fork(t_philo *philo, t_pdatas *datas)
{
	t_phidat	phidat;

	pthread_mutex_lock(&(philo->leftf->mutex));
	print(datas, philo, "take l🍴");
	if (datas->nb_p == 1)
	{
		phidat = (t_phidat){philo, datas};
		return(ft_usleep(datas->t_die), check_death(&phidat), (void)0);
	}
	pthread_mutex_lock(&(philo->rightf->mutex));
	print(datas, philo, "take r🍴");
}

void	eat(t_philo *philo, t_pdatas *datas)
{
	print(datas, philo, "eat 🍽️");
	philo->t_meal = get_time();
	ft_usleep(datas->t_eat);
	pthread_mutex_unlock(&(philo->leftf->mutex));
	pthread_mutex_unlock(&(philo->rightf->mutex));
	(philo->c_meal) += 1;
}

void	p_sleep(t_philo *philo, t_pdatas *datas)
{
	print(datas, philo, "sleep 😴");
	ft_usleep(datas->t_sleep);
}

void	think(t_philo *philo, t_pdatas *datas)
{
	print(datas, philo, "think 💭");
}