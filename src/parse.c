/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:58:22 by randre            #+#    #+#             */
/*   Updated: 2024/03/29 17:25:56 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

inline static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

inline static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static char	*valid_arg(const char *str)
{
	int		len;
	char	*num;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		exit_error("Invalid argument : Negative numbers are not allowed");
	if (!ft_isdigit(*str))
		exit_error("Invalid argument : not a number");
	num = (char *)str;
	while (ft_isdigit(*str))
	{
		str++;
		len++;
	}
	if (len > 10)
		exit_error("Invalid argument : over int_max");
	return (num);
}

static long	ft_atol(const char *str)
{
	char	*valid_str;
	long	number;

	valid_str = valid_arg(str);
	while (ft_isdigit(*valid_str))
	{
		number = (number * 10) + (*str - 48);
		valid_str++;
	}
	if (number > INT_MAX)
		exit_error("Invalid argument : over int_max");
	return (number);
}

void	parse(char **argv, t_table *table)
{
	table->nbr_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4 
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		exit_error("Timestamps must be over 60ms");
	if (argv[5])
		table->max_num_meals = ft_atol(argv[5]);
	else
		table->max_num_meals = -1;
}