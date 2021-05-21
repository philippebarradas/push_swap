/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:21:31 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/21 17:22:25 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void	sa(t_p *p, int x)
{
	int	tmp;

	if (p->lena > 0)
	{
		tmp = p->pa[p->lena];
		p->pa[p->lena] = p->pa[p->lena - 1];
		p->pa[p->lena - 1] = tmp;
		if (x == 0)
			ft_putstr_fd_count("sa\n", STDOUT, p);
	}
}

void	sb(t_p *p, int x)
{
	int	tmp;

	if (p->lenb > 0)
	{
		tmp = p->pb[p->lenb];
		p->pb[p->lenb] = p->pb[p->lenb - 1];
		p->pb[p->lenb - 1] = tmp;
		if (x == 0)
			ft_putstr_fd_count("sb\n", STDOUT, p);
	}
}

void	ss(t_p *p, int x)
{
	sb(p, 1);
	sa(p, 1);
	ft_putstr_fd_count("ss\n", STDOUT, p);
}

void	pa(t_p *p, int x)
{
	if (p->lenb >= 0)
	{
		p->lena++;
		p->pa[p->lena] = p->pb[p->lenb];
		p->lenb--;
		if (x == 0)
			ft_putstr_fd_count("pa\n", STDOUT, p);
	}
}

void	pb(t_p *p, int x)
{
	if (p->lena >= 0)
	{
		p->lenb++;
		p->pb[p->lenb] = p->pa[p->lena];
		p->lena--;
		if (x == 0)
			ft_putstr_fd_count("pb\n", STDOUT, p);
	}
}
