/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:03:55 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/19 13:38:06 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_bonus.h"

int	err_msg(char *str)
{
	ft_putstr_fd("Error\n", STDERR);
	return (ERROR);
}

int	check_error(int ac, char **av, int x, int y)
{
	while (++x < ac)
	{
		if (ft_strlen(av[x]) > 11 || ft_atol(av[x]) > 2147483647
			|| ft_atol(av[x]) < -2147483648)
			return (ERROR);
		if (ft_atoi(av[x]) == 0 && (av[x][0] != '0' || ft_strlen(av[x]) > 1))
			return (ERROR);
		if (av[x][0] == '0' && ft_strlen(av[x]) > 1)
			return (ERROR);
	}
	x = 0;
	while (++x < ac)
	{
		y = 0;
		while (++y < ac)
		{
			if (ft_strcmp(av[x], av[y]) == 0 && x != y)
				return (ERROR);
		}
	}
	return (SUCCESS);
}
