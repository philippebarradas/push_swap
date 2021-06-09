/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_loop3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:19:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 14:27:20 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

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

int	find_val_med(t_p *p, int div)
{
	int	i;
	int	max;
	int	min;
	int	e;

	e = 0;
	i = -1;
	max = p->pa[0];
	min = p->pa[0];
	while (++i <= p->lena)
	{
		if (p->pa[i] > max)
			max = p->pa[i];
		if (p->pa[i] < min)
			min = p->pa[i];
	}
	if ((p->lena % 2) == 1)
		e--;
	while (e <= (p->lena / div) && min <= max)
	{
		if (min_is_in_pa(p, min) == SUCCESS)
			e++;
		min++;
	}
	return (min);
}

int	pp_g_egg(int *pill, int len, int val_med)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] == val_med)
			return (i);
		i++;
	}
	return (i);
}

int	pp_d_egg(int *pill, int len, int val_med)
{
	int	i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] == val_med)
			return (i);
		i++;
	}
	return (i);
}
