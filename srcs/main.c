/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:08:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 13:08:29 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	fill_pile(int ac, char **av, t_p *p)
{
	int	i;
	int	e;

	i = ac - 1;
	e = 1;
	p->lena = ac - 2;
	p->lenb = -1;
	p->pa = malloc(sizeof(int) * (ac - 1));
	if (!(p->pa))
		return (ERROR);
	p->pb = malloc(sizeof(int) * (ac - 1));
	if (!(p->pa))
		return (ERROR);
	while (i > 0)
	{
		p->pa[i - 1] = ft_atoi(av[e]);
		e++;
		i--;
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

int	abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void	ft_putstr_fd_count(char *s, int fd, t_p *p)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &(s[i]), 1);
	p->count++;
	disp_st(p);
}

int	loop_t_arg(t_p *p)
{
	int	a;
	int	b;
	int	c;

	a = p->pa[2];
	b = p->pa[1];
	c = p->pa[0];
	if (a < b && b > c && a < c)
	{
		rra(p, 0);
		sa(p, 0);
	}
	else if (a < b && b > a && a > c)
		rra(p, 0);
	else if (a > b && b < c && c > a)
		sa(p, 0);
	else if (a > b && b < c && a > c)
		ra(p, 0);
	else if (a > b && b > c && a > c)
	{
		ra(p, 0);
		sa(p, 0);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_p	*p;
	int	i;

	if (check_error(ac, av, 0, 0) == 1)
		return (err_msg("Error\n"));
	if (ac == 1)
		return (SUCCESS);
	p = malloc(sizeof(t_p));
	if (!p)
		return (ERROR);
	if (fill_pile(ac, av, p) == ERROR)
	{
		free(p);
		return (err_msg("Error\n"));
	}
	p->count = 0;
	i = 0;
	p->max = p->pa[i];
	p->maxe = p->pa[i];
	p->min = p->pa[i];
	while (i <= p->lena)
	{
		if (abs(p->pa[i]) > p->max)
			p->max = abs(p->pa[i]);
		if (p->pa[i] > p->maxe)
			p->maxe = p->pa[i];
		if (p->pa[i] < p->min)
			p->min = p->pa[i];
		i++;
	}
	p->max += 10;
	if (p->lena < 3)
		return (loop_t_arg(p));
	if (p->lena < 10)
		return (loop(p));
	return (long_loop(p));
}
