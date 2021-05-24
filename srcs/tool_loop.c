/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/24 09:29:26 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	pa_is_trim(t_p *p)
{
	int	i;

	i = 0;
	while (i + 1 <= p->lena)
	{
		if (p->pa[i] < p->pa[i + 1])
		{
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	pb_is_trim(t_p *p)
{
	int	i;

	i = 0;
	while (i + 1 <= p->lenb)
	{
		if (p->pb[i] > p->pb[i + 1])
		{
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	pb_top_is_min(t_p *p)
{
	int	i;

	i = 0;
	if (p->lenb == -1)
		return (ERROR);
	while (i <= p->lenb)
	{
		if (p->pb[p->lenb] > p->pb[i])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	pa_top_is_max(t_p *p)
{
	int	i;

	i = 0;
	while (i <= p->lena)
	{
		if (p->pb[0] < p->pa[i])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	no_val_med_in_a(t_p *p, int val_med)
{
	int	i;

	i = 0;
	while (i <= p->lena)
	{
		if (p->pa[i] < val_med)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	no_val_med_in_b(t_p *p, int val_med)
{
	int	i;

	i = 0;
	while (i <= p->lenb)
	{
		if (p->pb[i] >= val_med)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	min_is_in_pa(t_p *p, int min)
{
	int	r;

	r = 0;
	while (r <= p->lena)
	{
		if (min == p->pa[r])
			return (SUCCESS);
		r++;
	}
	return (ERROR);
}

int	find_val_med(t_p *p)
{
	int	i;
	int	max;
	int	min;
	int	e;

	e = 0;
	i = 0;
	max = p->pa[i];
	min = p->pa[i];
	while (i <= p->lena)
	{
		if (p->pa[i] > max)
			max = p->pa[i];
		if (p->pa[i] < min)
			min = p->pa[i];
		i++;
	}
	if ((p->lena % 2) == 1)
		e--;
	while (e < ((p->lena) / 2) && min < max)
	{
		if (min_is_in_pa(p, min) == SUCCESS)
			e++;
		min++;
	}
	return (min);
}

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

int	find_val_med_in_b(t_p *p)
{
	int	i;
	int	max;
	int	min;
	int	e;

	e = 0;
	i = 0;
	max = p->pb[i];
	min = p->pb[i];
	while (i <= p->lenb)
	{
		if (p->pb[i] > max)
			max = p->pb[i];
		if (p->pb[i] < min)
			min = p->pb[i];
		i++;
	}
	if ((p->lenb % 2) == 1)
		e--;
	while (e < ((p->lenb) / 2) && min < max)
	{
		if (min_is_in_pb(p, max) == SUCCESS)
			e++;
		max--;
	}
	return (max);
}

int	is_in_pill(int *pil, int nbr)
{
	int	i;

	i = 0;
	while (pil[i])
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
			if (is_in_pill(p->pa, next) == SUCCESS
				|| is_in_pill(p->pb, next) == SUCCESS)
				return (ERROR);
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
			if (is_in_pill(p->pb, next) == SUCCESS
				|| is_in_pill(p->pa, next) == SUCCESS)
				return (ERROR);
			next--;
		}
		e++;
	}
	return (SUCCESS);
}
