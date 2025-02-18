/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:59:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/18 12:43:01 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

///////////////////////////////////////////////////////////////////////////////
// function for obtain the current time in micro second
long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

///////////////////////////////////////////////////////////////////////////////
// Converts a string to an integer
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] <= 57 && str[i] >= 48) && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

///////////////////////////////////////////////////////////////////////////////
// clean if init fail
int	clean_init(t_philo *philos, t_fourch *fourchs, int i)
{
	pthread_mutex_destroy(&fourchs[i].mutex);
	while (--i >= 0)
		pthread_mutex_destroy(&fourchs[i].mutex);
	free(fourchs);
	free(philos);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// init all structs needed by the software
t_philo	*init_structs(int nb, t_pdatas datas)
{
	int			i;
	t_fourch	*temp;
	t_fourch	*fourchs;
	t_philo		*philos;

	if (nb <= 0)
		return (NULL);
	fourchs = malloc(sizeof(t_fourch) * nb);
	if (!fourchs)
		return (NULL);
	philos = malloc(sizeof(t_philo) * nb);
	if (!philos)
		return (free(fourchs), NULL);
	i = 0;
	while (i < nb)
	{
		fourchs[i].id = i;
		if (pthread_mutex_init(&fourchs[i].mutex, NULL) != 0)
			return (clean_init(philos, fourchs, i), NULL);
		temp = &fourchs[(i + 1) % nb];
		philos[i] = (t_philo){i, datas.t_start, 0, NULL, &fourchs[i], temp, {}};
		pthread_mutex_init(&(philos[i].meal_mutex), NULL);
		i++;
	}
	return (philos);
}

///////////////////////////////////////////////////////////////////////////////
// function usleep more fast
void	ft_usleep(int ms)
{
	long int	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(ms / 10);
}
