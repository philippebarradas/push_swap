/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:08:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/20 17:07:08 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_bonus.h"

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

	while (1)
	{
		get_next_line(0, &cmd);
		if (cmd[0] <= 0)
		{
			if (is_sort(p) == ERROR)
				return (ft_putstr_fd_ret("K0\n", STDOUT, ERROR));
			else
				return (ft_putstr_fd_ret("OK\n", STDOUT, SUCCESS));
		}
		if (find_cmd(cmd, p) == ERROR)
		{
			free_all(p);
			free(cmd);
			return (ERROR);
		}
		//ft_putstr_fd("\033c", STDOUT);
		//disp_st(p, "o");
		ffree(cmd);
	}
	//disp_st(p, "o");
	free(p);
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
	//disp_st(p, "bef");
	return (loop(p));
}
