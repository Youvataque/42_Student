/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:39:47 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/19 16:21:37 by yseguin          ###   ########.fr       */
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
	int				max_meal;
	int				end;
	t_fourch		*fourchs;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	write_mutex;
}	t_pdatas;

typedef struct s_philo
{
	int				id;
	long			t_meal;
	int				c_meal;
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
int		ended(t_pdatas *datas, int update);
int		is_finished(t_philo *philo, t_pdatas *datas);
int		is_dead(t_philo *philo, t_pdatas *datas);
int		check_all(int ac, char **av);
long	get_time(void);
void	ft_usleep(int ms);
t_philo	*init_structs(int nb, t_pdatas *datas);

/* actions */
void	print(t_pdatas *datas, t_philo *philo, char *str);
void	*check_death(void *arg);
void	take_fork(t_philo *philo, t_pdatas *datas);
void	eat(t_philo *philo, t_pdatas *datas);
void	p_sleep(t_philo *philo, t_pdatas *datas);
void	think(t_philo *philo, t_pdatas *datas);
#endif