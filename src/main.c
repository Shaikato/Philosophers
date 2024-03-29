/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:54:48 by randre            #+#    #+#             */
/*   Updated: 2024/03/29 17:25:22 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;
	if (argc == 5 || argc == 6)
	{
		parse(argv, &table);
		//init();
		//start_dinner();
	}
	else
		exit_error("Wrong number or arguments");
}