/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:59:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/07 13:00:29 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/////////////////////////////////////////////////////////////////////////////
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