/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:08:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/11 16:33:41 by user42           ###   ########.fr       */
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
	return (SUCCESS);
}

int	find_cmd(char *cmd, t_p *p)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		sa(p);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		sb(p);
	else if (ft_strcmp(cmd, "ss\n") == 0)
		ss(p);
	else if (ft_strcmp(cmd, "pa\n") == 0)
		pa(p);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		pb(p);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		ra(p);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		rb(p);
	else if (ft_strcmp(cmd, "rr\n") == 0)
		rr(p);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		rra(p);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		rrb(p);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		rrr(p);
	else
		return (ERROR);
	return (SUCCESS);
}

int	lleave(t_p *p, char *cmd)
{
	if (ft_strcmp(cmd, "\n") == 0)
	{
		free(cmd);
		free_all(p);
		return (ft_putstr_fd_ret("Error\n", STDERR, ERROR));
	}
	if (is_sort(p) == ERROR)
	{
		free_all(p);
		ffree(cmd);
		return (ft_putstr_fd_ret("K0\n", STDERR, ERROR));
	}
	free_all(p);
	ffree(cmd);
	return (ft_putstr_fd_ret("OK\n", STDOUT, SUCCESS));
}

int	loop(t_p *p)
{
	char	*cmd;

	cmd = NULL;
	while (1)
	{
		get_next_line(0, &cmd);
		if (cmd[0] <= 0)
			return (lleave(p, cmd));
		else if (find_cmd(cmd, p) == ERROR)
		{
			free_all(p);
			ffree(cmd);
			return (ft_putstr_fd_ret("Error\n", STDERR, ERROR));
		}
		ffree(cmd);
	}
	free_all(p);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_p	*p;

	if (ac == 1)
		return (SUCCESS);
	if (check_error(ac, av, 0, 0) == 1)
		return (err_msg("Error\n"));
	p = malloc(sizeof(t_p));
	if (!p)
		return (ERROR);
	if (fill_pile(ac, av, p) == ERROR)
	{
		free(p);
		return (err_msg("Error\n"));
	}
	return (loop(p));
}
