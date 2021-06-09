/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:24:41 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 14:24:51 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

void	first_meed(t_p *p)
{
	p->div = 0;
	p->init_lena = p->lena;
	p->init_med = find_val_med(p, 2);
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
}

void	rot_min(t_p *p)
{
	if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb,
			next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
		rr(p, 1);
	else
		ra(p, 0);
	p->min = next_min(p);
}

int	long_loop(t_p *p)
{
	first_meed(p);
	while (is_sort(p) == ERROR)
	{
		find_max_b(p);
		if (p->pa[p->lena] == p->min)
			rot_min(p);
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] == p->max_b && p->lenb >= 1)
			pa(p, 0);
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] != p->min)
			find_min_in_b(p);
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS
			&& p->pb[p->lenb] == p->min)
			min_pb_top(p);
		else if (is_in_pill(p->pa, p->min, p->lena) == SUCCESS)
			pb(p, 0);
	}
	free(p);
	return (SUCCESS);
}
