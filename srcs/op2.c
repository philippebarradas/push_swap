/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:39:42 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 14:48:07 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void	ra(t_p *p, int x)
{
	int	tmp;
	int	i;

	i = p->lena;
	if (p->lena >= 0)
	{
		tmp = p->pa[p->lena];
		while (i > 0)
		{
			p->pa[i] = p->pa[i - 1];
			i--;
		}
		p->pa[0] = tmp;
		if (x == 0)
			ft_putstr_fd_count("ra\n", STDOUT, p);
	}
}

void	rb(t_p *p, int x)
{
	int	tmp;
	int	i;

	i = p->lenb;
	if (p->lenb >= 0)
	{
		tmp = p->pb[p->lenb];
		while (i > 0)
		{
			p->pb[i] = p->pb[i - 1];
			i--;
		}
		p->pb[0] = tmp;
		if (x == 0)
			ft_putstr_fd_count("rb\n", STDOUT, p);
	}
}

void	rr(t_p *p, int x)
{
	(void)x;
	ra(p, 1);
	rb(p, 1);
	ft_putstr_fd_count("rr\n", STDOUT, p);
}

void	rra(t_p *p, int x)
{
	int	tmp;
	int	i;

	i = 0;
	if (p->lena >= 0)
	{
		tmp = p->pa[0];
		while (i < p->lena)
		{
			p->pa[i] = p->pa[i + 1];
			i++;
		}
		p->pa[p->lena] = tmp;
		if (x == 0)
			ft_putstr_fd_count("rra\n", STDOUT, p);
	}
}

void	rrb(t_p *p, int x)
{
	int	tmp;
	int	i;

	i = 0;
	if (p->lenb >= 0)
	{
		tmp = p->pb[0];
		while (i < p->lenb)
		{
			p->pb[i] = p->pb[i + 1];
			i++;
		}
		p->pb[p->lenb] = tmp;
		if (x == 0)
			ft_putstr_fd_count("rrb\n", STDOUT, p);
	}
}
