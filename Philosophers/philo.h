/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:39:47 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/07 13:31:50 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/* structs */
typedef struct s_philo
{
	int	nb_p;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	max_eat;
}	t_philo;

/* functions */
int	ft_atoi(const char *str);

#endif