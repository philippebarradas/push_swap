/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:08:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/20 16:34:53 by phbarrad         ###   ########.fr       */
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
/*	i = -1;
	while (++i < ac - 1)
		printf("a = [%d] \n", p->pa[i]);
	printf("\n");*/
	return (SUCCESS);
}

int	find_cmd(char *cmd, t_p *p)
{
	if (ft_strcmp(cmd, "sa") == 0)
		sa(p);
	else if (ft_strcmp(cmd, "sb") == 0)
		sb(p);
	else if (ft_strcmp(cmd, "ss") == 0)
		ss(p);
	else if (ft_strcmp(cmd, "pa") == 0)
		pa(p);
	else if (ft_strcmp(cmd, "pb") == 0)
		pb(p);
	else if (ft_strcmp(cmd, "ra") == 0)
		ra(p);
	else if (ft_strcmp(cmd, "rb") == 0)
		rb(p);
	else if (ft_strcmp(cmd, "rr") == 0)
		rr(p);
	else if (ft_strcmp(cmd, "rra") == 0)
		rra(p);
	else if (ft_strcmp(cmd, "rrb") == 0)
		rrb(p);
	else if (ft_strcmp(cmd, "rrr") == 0)
		rrr(p);
	else
		return (ERROR);
	return (SUCCESS);
}

int	is_sort(t_p *p)
{
	int	i;

	i = 0;
	//printf("len b = [%d]\n", p->lenb);
	if (p->lenb != -1)
		return (ERROR);
	while (i + 1 <= p->lena)
	{
		if (p->pa[i] < p->pa[i + 1])
		{
			//printf("len b = [%d][%d]\n", p->pa[i], p->pa[i + 1]);
			return (ERROR);
		}
		i++;
	}
	//printf("SORTED\n\n");
	return (SUCCESS);
}

int abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int	main(int ac, char **av)
{
	t_p	*p;

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
	//ft_putstr_fd("\033c", STDOUT);
	int	i;

	i = 0;
	p->max = 0;
	while (i  <= p->lena)
	{
		if (abs(p->pa[i]) > p->max)
			p->max = abs(p->pa[i]);
		i++;
	}
	p->max += 10;
	//disp_st(p);
	//ft_putstr_fd("\n", STDOUT);
	//return (0);
	return (loop(p));
}
