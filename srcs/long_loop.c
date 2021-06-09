/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 12:57:42 by phbarrad         ###   ########.fr       */
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

void	fillpa_sec_med(t_p *p, float av, int len)
{
	while (p->lenb >= 0 && no_val_med_in_b(p, p->val_med_b) != SUCCESS
		&& pb_opti_fill(p) == ERROR)
	{
		find_max_b(p);
		p->val_med_a = find_val_med(p, 3);
		if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] == p->min)
		{
			pa(p, 0);
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb,
					next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		}
		else if (p->pb[p->lenb] >= p->val_med_b || p->pb[p->lenb] == p->max_b)
		{
			pa(p, 0);
			if (p->pa[p->lena] == p->min)
			{
				ra(p, 0);
				p->min = next_min(p);
			}
		}
		else if (pp_g(p->pb, p->lenb, p->val_med_b) == pp_d(p->pb, p->lenb,
				p->val_med_b)
			&& pp_g_val(p->pb, p->lenb, p->val_med_b) > pp_d_val(p->pb, p->lenb,
				p->val_med_b))
			rrb(p, 0);
		else if (pp_g(p->pb, p->lenb, p->val_med_b) < pp_d(p->pb, p->lenb,
				p->val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		if (no_val_med_in_b(p, p->val_med_b) == SUCCESS && p->lenb >= len)
			p->val_med_b = find_val_med_in_b(p, av);
	}
}

int	long_loop(t_p *p)
{
	int	initmin;
	int	r;
	int	mi;
	int	ma;

	p->div = 0;
	p->init_lena = p->lena;
	p->init_med = find_val_med(p, 2);
	r = 0;
	initmin = p->min;
	if (p->lena < 200)
	{
		p->val_med_a = find_val_med(p, 2);
		fillpb_first_med(p, 2, 15);
		p->val_med_b = find_val_med_in_b(p, 3);
		fillpa_sec_med(p, 3, 15);
	}
	else if (p->lena >= 200)
	{
		p->val_med_a = find_val_med(p, 3);
		fillpb_first_med(p, 3, 0);
		p->val_med_b = find_val_med_in_b(p, 9);
		fillpa_sec_med(p, 6, p->init_lena / 15);
	}
	while (is_sort(p) == ERROR && r == 0)
	{
		mi = 0;
		ma = 0;
		find_max_b(p);
		if (p->pa[p->lena] == p->min)
		{
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb,
					next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		}
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] == p->max_b && p->lenb >= 1)
			pa(p, 0);
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] != p->min)
		{
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
			else if (pp_d_egg(p->pb, p->lenb, p->min) < pp_d_egg(p->pb,
					p->lenb, p->max_b) && ma == mi && 1 == 1)
				rb(p, 0);
			else if (pp_d_egg(p->pb, p->lenb, p->min) > pp_d_egg(p->pb,
					p->lenb, p->max_b) && ma == mi && 1 == 1)
				rrb(p, 0);
			else
				rb(p, 0);
		}	
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] == p->min)
		{
			pa(p, 0);
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb,
					next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		}
		else if (is_in_pill(p->pa, p->min, p->lena) == SUCCESS)
			pb(p, 0);
	}
	free(p);
	return (SUCCESS);
}
