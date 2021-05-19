/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:08:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/19 16:53:37 by phbarrad         ###   ########.fr       */
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
	i = -1;
	while (++i < ac - 1)
		printf("a = [%d] \n", p->pa[i]);
	printf("\n");
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

int	loop(t_p *p)
{
	char	*cmd;
	int	x;
	int y;
	int i;

	i = 0;
	x = p->lena;
	y = 0;
	int e;

	e = 0;
	while (i < 10000000 && is_sort(p) == ERROR)
	{
		if (p->lenb != -1)
		{
			ft_putstr_fd("pa\n", STDOUT);
			i++;
			pa(p);
			pa(p);
					disp_st(p);


		}
		if (p->lena != -1)
		{
			ft_putstr_fd("pb\n", STDOUT);
			i++;
			pb(p);
			pb(p);
					disp_st(p);


		}
		if (p->pa[p->lena] > p->pa[0])
		{
			ft_putstr_fd("ra\n", STDOUT);
			ra(p);
					disp_st(p);

		}
		else if (p->pa[p->lena] > p->pa[p->lena - 1])
		{
			sa(p);
			printf("[%d]\n", p->lena);
			ft_putstr_fd("sa\n", STDOUT);
					disp_st(p);

		}
		else if (p->pa[0] < p->pa[p->lena])
		{
			ft_putstr_fd("rra\n", STDOUT);
			rra(p);
					disp_st(p);

		}
		else
		{
			ft_putstr_fd("pb\n", STDOUT);
			pb(p);
					disp_st(p);

		}
		if (p->lenb >= x)
		{


				ft_putstr_fd("pa\n", STDOUT);
				pa(p);
						disp_st(p);


		}
		if (p->pa[0] == 0)
			return (ERROR);
/*		if (x == 0)
		{
			x = p->lena;
		}*/
			//sa(p);

/*		else if (p->pb[p->lenb] < p->pb[0])
			rb(p);
		else if (p->lenb < p->lena)
			pb(p);
		else if (p->lenb > 0)
			pa(p);*/

		//ft_putstr_fd("\n", STDOUT);
		i++;
		//ft_putstr_fd("\033c", STDOUT);
	}
	disp_st(p);
	free(p);
	return (SUCCESS);
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
	//ft_putstr_fd("\n", STDOUT);
	///disp_st(p);
	//ft_putstr_fd("\n", STDOUT);

	return (loop(p));
}
