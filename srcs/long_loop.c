/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 14:36:31 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void	fillpb_first_med(t_p *p, float av, int len)
{
	while (pa_opti_fill(p) == ERROR && p->lena >= 0
		&& no_val_med_in_a(p, p->val_med_a) == ERROR)
	{
		if (p->pa[p->lena] < p->val_med_a)
			pb(p, 0);
		else if (p->pa[0] < p->val_med_a && p->pa[0] < p->pa[p->lena - 1])
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, p->val_med_a) == SUCCESS && p->lena >= len)
			p->val_med_a = find_val_med(p, av);
	}
}

void	min_pb_top(t_p *p)
{
	pa(p, 0);
	if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb,
			next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
		rr(p, 1);
	else
		ra(p, 0);
	p->min = next_min(p);
}

void	oth(t_p *p)
{
	if (pp_g(p->pb, p->lenb, p->val_med_b) == pp_d(p->pb, p->lenb,
			p->val_med_b)
		&& pp_g_val(p->pb, p->lenb, p->val_med_b) > pp_d_val(p->pb, p->lenb,
			p->val_med_b))
		rrb(p, 0);
	else if (pp_g(p->pb, p->lenb, p->val_med_b) < pp_d(p->pb, p->lenb,
			p->val_med_b))
		rrb(p, 0);
	else
		rb(p, 0);
}

void	fillpa_sec_med(t_p *p, float av, int len)
{
	while (p->lenb >= 0 && no_val_med_in_b(p, p->val_med_b) != SUCCESS
		&& pb_opti_fill(p) == ERROR)
	{
		find_max_b(p);
		p->val_med_a = find_val_med(p, 3);
		if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] == p->min)
			min_pb_top(p);
		else if (p->pb[p->lenb] >= p->val_med_b || p->pb[p->lenb] == p->max_b)
		{
			pa(p, 0);
			if (p->pa[p->lena] == p->min)
			{
				ra(p, 0);
				p->min = next_min(p);
			}
		}
		else
			oth(p);
		if (no_val_med_in_b(p, p->val_med_b) == SUCCESS && p->lenb >= len)
			p->val_med_b = find_val_med_in_b(p, av);
	}
}

void	find_min_in_b(t_p *p)
{
	int	mi;
	int	ma;

	mi = 0;
	ma = 0;
	if (pp_g_egg(p->pb, p->lenb, p->min) <= pp_d_egg(p->pb,
			p->lenb, p->min))
		mi = pp_g_egg(p->pb, p->lenb, p->min);
	else
		mi = pp_d_egg(p->pb, p->lenb, p->min);
	if (pp_g_egg(p->pb, p->lenb, p->max_b) <= pp_d_egg(p->pb,
			p->lenb, p->max_b))
		ma = pp_g_egg(p->pb, p->lenb, p->max_b);
	else
		ma = pp_d_egg(p->pb, p->lenb, p->max_b);
	if ((pp_g_egg(p->pb, p->lenb, p->max_b) < pp_g_egg(p->pb, p->lenb,
				p->min) && mi > ma) || (pp_g_egg(p->pb, p->lenb,
				p->min) < pp_g_egg(p->pb, p->lenb, p->max_b)
			&& ma > mi))
		rrb(p, 0);
	else
		rb(p, 0);
}
