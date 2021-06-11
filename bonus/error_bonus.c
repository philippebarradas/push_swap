/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:03:55 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/11 12:48:09 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_bonus.h"

int	err_msg(char *str)
{
	ft_putstr_fd(str, STDERR);
	return (ERROR);
}

int	check_is_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57))
		{
			if ((str[i] == '-' || str[i] == '+') && i == 0)
				;
			else
				return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_error(int ac, char **av, int x, int y)
{
	while (++x < ac)
	{
		if (check_is_numbers(av[x]) == ERROR)
			return (ERROR);
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

int	is_sort(t_p *p)
{
	int	i;

	i = 0;
	if (p->lenb != -1)
		return (ERROR);
	while (i + 1 <= p->lena)
	{
		if (p->pa[i] < p->pa[i + 1])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
