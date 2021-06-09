/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:49:25 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 12:49:27 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	next_val_med_pa(t_p *p)
{
	int	e;
	int	min;

	min = p->pa[p->lena];
	e = p->lena;
	while (e >= 0)
	{
		if (p->pa[e] < min)
			min = p->pa[e];
		e--;
	}
	return (min);
}

int	pp_g_med(int *pill, int len, int val_med)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] <= val_med)
			return (i);
		i++;
	}
	return (i);
}

int	pp_d_med(int *pill, int len, int val_med)
{
	int	i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] <= val_med)
			return (i);
		i++;
	}
	return (i);
}

int	next_min(t_p *p)
{
	int	e;
	int	reta;
	int	retb;

	e = 0;
	reta = p->max;
	while (e <= p->lena)
	{
		if (p->pa[e] < reta && p->pa[e] > p->min)
			reta = p->pa[e];
		e++;
	}
	e = 0;
	retb = p->max;
	while (e <= p->lenb)
	{
		if (p->pb[e] < retb && p->pb[e] > p->min)
			retb = p->pb[e];
		e++;
	}
	if (reta < retb)
		return (reta);
	return (retb);
}

void	find_max_b(t_p *p)
{
	int	i;
	int	max;

	if (p->lenb == -1)
	{
		max = 0;
		return ;
	}
	max = p->pb[0];
	i = 0;
	while (i <= p->lenb)
	{
		if (p->pb[i] > max)
			max = p->pb[i];
		i++;
	}
	p->max_b = max;
}
