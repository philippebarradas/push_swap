/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:21:31 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/19 14:38:18 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_bonus.h"

void	sa(t_p *p)
{
	int	tmp;

	if (p->lena >= 0)
	{
		tmp = p->pa[p->lena];
		p->pa[p->lena] = p->pa[p->lena - 1];
		p->pa[p->lena - 1] = tmp;
	}
}

void	sb(t_p *p)
{
	int	tmp;

	if (p->lenb >= 0)
	{
		tmp = p->pb[p->lenb];
		p->pb[p->lenb] = p->pb[p->lenb - 1];
		p->pb[p->lenb - 1] = tmp;
	}
}

void	ss(t_p *p)
{
	sb(p);
	sa(p);
}

void	pa(t_p *p)
{
	if (p->lenb >= 0)
	{
		p->lena++;
		p->pa[p->lena] = p->pb[p->lenb];
		p->lenb--;
	}
}

void	pb(t_p *p)
{
	if (p->lena >= 0)
	{
		p->lenb++;
		p->pb[p->lenb] = p->pa[p->lena];
		p->lena--;
	}
}
