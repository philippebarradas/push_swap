/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:37:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/19 14:38:27 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_bonus.h"

void	ra(t_p *p)
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
	}
}

void	rb(t_p *p)
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
	}
}

void	rr(t_p *p)
{
	ra(p);
	rb(p);
}

void	rra(t_p *p)
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
	}
}

void	rrb(t_p *p)
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
	}
}
