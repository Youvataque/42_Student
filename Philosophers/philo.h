/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:39:47 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/12 14:45:54 by yseguin          ###   ########.fr       */
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
# include <limits.h>

/* structs */
typedef struct s_fourch
{
	int				id;
	pthread_mutex_t	mutex;
}	t_fourch;

typedef struct s_pdatas
{
	int				nb_p;
	long			t_start;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_eat;
	int				end;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	write_mutex;
}	t_pdatas;

typedef struct s_philo
{
	int				id;
	long			t_meal;
	pthread_t		thread;
	t_fourch		*rightf;
	t_fourch		*leftf;
	pthread_mutex_t	meal_mutex;
}	t_philo;

typedef struct s_phidat
{
	t_philo		*philos;
	t_pdatas	*datas;
}	t_phidat;

/* functions */
int		ft_atoi(const char *str);
long	get_time(void);
int		ended(t_pdatas *datas, int update);
t_philo	*init_structs(int nb, t_pdatas datas);

/* actions */
void	take_fork(t_philo *philo, t_pdatas *datas);
void	eat(t_philo *philo, t_pdatas *datas);
void	p_sleep(t_philo *philo, t_pdatas *datas);
void	think(t_philo *philo, t_pdatas *datas);
void	*check_death(void *arg);
#endif