/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:44:47 by randre            #+#    #+#             */
/*   Updated: 2024/03/29 17:25:27 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_table t_table;

typedef pthread_mutex_t t_mtx;

typedef struct s_fork
{
	int		fork_id;
	t_mtx	fork;	
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meal_counters;
	bool		full;
	long		last_meal;
	t_fork		*r_fork;
	t_fork		*l_fork;
	pthread_t	thread_id;
	t_table		*table;
} 				t_philo;

struct s_table
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_num_meals;
	long	start;
	bool	end;
	t_fork	*forks;
	t_philo	*philos;	
};

void	exit_error(const char *error);
void	parse(char **argv, t_table *table);

#endif