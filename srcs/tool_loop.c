/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 13:19:01 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	min_is_in_pb(t_p *p, int max)
{
	int	r;

	r = 0;
	while (r <= p->lenb)
	{
		if (max == p->pb[r])
			return (SUCCESS);
		r++;
	}
	return (ERROR);
}

int	find_val_med_in_b(t_p *p, int div)
{
	int	i;
	int	max;
	int	min;
	int	e;

	e = 0;
	i = -1;
	max = p->pb[0];
	min = p->pb[0];
	while (++i <= p->lenb)
	{
		if (p->pb[i] > max)
			max = p->pb[i];
		if (p->pb[i] < min)
			min = p->pb[i];
	}
	if ((p->lenb % 2) == 1)
		e--;
	while (e <= (p->lenb / div) && min <= max)
	{
		if (min_is_in_pb(p, max) == SUCCESS)
			e++;
		max--;
	}
	return (max);
}

int	is_in_pill(int *pil, int nbr, int len)
{
	int	i;

	i = 0;
	if (len == -1)
		return (ERROR);
	while (i <= len)
	{
		if (pil[i] == nbr)
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int	pa_opti_fill(t_p *p)
{
	int	e;
	int	next;

	e = 0;
	if (p->pa[0] != p->maxe)
		return (ERROR);
	while (e < p->lena)
	{
		next = p->pa[e + 1] + 1;
		while (next < p->pa[e])
		{
			if (is_in_pill(p->pa, next, p->lena) == SUCCESS
				|| is_in_pill(p->pb, next, p->lenb) == SUCCESS)
				return (ERROR);
			if (p->maxe <= 0)
				next--;
			else
				next++;
		}
		e++;
	}
	return (SUCCESS);
}

int	pb_opti_fill(t_p *p)
{
	int	e;
	int	next;

	e = 0;
	if (p->pb[0] != p->min)
		return (ERROR);
	while (e < p->lenb)
	{
		next = p->pb[e + 1] - 1;
		while (next > p->pb[e])
		{
			if (is_in_pill(p->pb, next, p->lenb) == SUCCESS
				|| is_in_pill(p->pa, next, p->lena) == SUCCESS)
				return (ERROR);
			if (p->min >= 0)
				next++;
			else
				next--;
		}
		e++;
	}
	return (SUCCESS);
}
