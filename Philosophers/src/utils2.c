/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:36:24 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/24 20:17:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

///////////////////////////////////////////////////////////////////////////////
// check if a char c is a <= 9 & >= 0
int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// check if the str is a positive number
int	str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// check if all args are positive number
int	check_all(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!str_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
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
