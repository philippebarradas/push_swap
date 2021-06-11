/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/11 09:28:57 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void	sswap(t_p *p)
{
	if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		&& (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
		ss(p, 1);
	else if (p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		sa(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
		sb(p, 0);
}

void	bef_val_med_in_a(t_p *p)
{
	int	val_med;

	while (pa_is_trim(p) == ERROR && is_sort(p) == ERROR)
	{
		val_med = find_val_med(p, 2);
		sswap(p);
		while (no_val_med_in_a(p, val_med) == ERROR && pa_is_trim(p) == ERROR)
		{
			if (p->pa[p->lena] < val_med)
				pb(p, 0);
			else if (p->pa[0] < val_med)
				rra(p, 0);
			else
				ra(p, 0);
			sswap(p);
		}
	}
}

void	bef_val_med_in_b(t_p *p)
{
	int	val_med;

	while (is_sort(p) == ERROR && pa_is_trim(p) != ERROR && p->lenb > 0)
	{
		val_med = find_val_med_in_b(p, 2);
		sswap(p);
		while (no_val_med_in_b(p, val_med) == ERROR)
		{
			if (p->pb[p->lenb] >= val_med)
				pa(p, 0);
			else if (p->pb[0] >= val_med)
				rrb(p, 0);
			else
				rb(p, 0);
			sswap(p);
		}
	}
}

int	loop(t_p *p)
{
	while (is_sort(p) == ERROR)
	{
		if (pa_is_trim(p) == ERROR && p->lena != -1)
			bef_val_med_in_a(p);
		else if (pb_is_trim(p) == ERROR && p->lenb != -1)
			bef_val_med_in_b(p);
		else
			pa(p, 0);
	}
	free_all(p);
	return (SUCCESS);
}
