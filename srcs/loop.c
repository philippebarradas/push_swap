/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/02 10:39:43 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"
/*
void	first_algo(t_p *p)
{
	if (((p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])) &&
	((p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])))
		rrr(p, 1);
 	else if (p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])
		rra(p, 0);
 	else if (p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])
		rrb(p, 0);

	if ((p->lenb >= 1 && p->pb[p->lenb] < p->pb[0]) &&
	(p->lena >= 1 && p->pa[p->lena] > p->pa[0]))
		rr(p, 1);
	else if (p->lena >= 1 && p->pa[p->lena] > p->pa[0])
		ra(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[0])
		rb(p, 0);

	if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])&&
	(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
		ss(p, 1);
	else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		sa(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
		sb(p, 0);

	if (pa_is_trim(p) == ERROR)
		pb(p, 0);
	else if (pa_is_trim(p) == SUCCESS && p->lenb > -1 && p->lena != -1 && is_sort(p) == ERROR)
		pa(p, 0);
}

int median_algo(int r, int med, t_p *p)
{
	int v = 0;
	while (r <= med && is_sort(p) == ERROR && pa_is_trim(p) == ERROR)
	{
		if (((p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])) &&
		((p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])))
			rrr(p, 1);
		else if (p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])
			rra(p, 0);
 		else if (p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])
			rrb(p, 0);

		if ((p->lenb >= 1 && p->pb[p->lenb] < p->pb[0]) &&
		(p->lena >= 1 && p->pa[p->lena] > p->pa[0]))
			rr(p, 1);
		else if (p->lena >= 1 && p->pa[p->lena] > p->pa[0])
			ra(p, 0);
		else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[0])
			rb(p, 0);

		if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])&&
		(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
			ss(p, 1);
 		else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
			sa(p, 0);
		else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
			sb(p, 0);

		pb(p, 0);
	}
	return (r);
}

void 	sort_indiv(t_p *p)
{
		if ((p->lenb >= 1 && p->pb[p->lenb] < p->pb[0]) &&
		(p->lena >= 1 && p->pa[p->lena] > p->pa[0]))
			rr(p, 1);
		else if (p->lena >= 1 && p->pa[p->lena] > p->pa[0])
			ra(p, 0);
		else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[0])
			rb(p, 0);
		else if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])&&
		(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
			ss(p, 1);
		else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
			sa(p, 0);
		else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
			sb(p, 0);
		else if (((p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])) &&
		((p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])))
			rrr(p, 1);
 		else if (p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])
			rra(p, 0);
 		else if (p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])
			rrb(p, 0);

		if (pa_is_trim(p) != SUCCESS && p->lena >= 0 && p->pa[p->lena] > p->pb[p->lenb])
			pb(p, 0);
		else if (pb_is_trim(p) != SUCCESS && p->lenb >= 0 && p->pa[p->lena] < p->pb[p->lenb])
			pa(p, 0);
		else if (pa_is_trim(p) == SUCCESS && is_sort(p) == ERROR)
			pa(p, 0);
		else if (pb_is_trim(p) == SUCCESS && is_sort(p) == ERROR)
			pb(p, 0);
}
 */
void	sswap(t_p *p)
{
	if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])&&
	(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
		ss(p, 1);
	else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		sa(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
		sb(p, 0);
}

void	rrotate(t_p *p)
{

 	if ((p->lenb >= 1 && p->pb[p->lenb] < p->pb[0]) &&
	(p->lena >= 1 && p->pa[p->lena] > p->pa[0]))
		rr(p, 1);
	else if (p->lena >= 1 && p->pa[p->lena] > p->pa[0])
		ra(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[0])
		rb(p, 0);

	if (((p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])) &&
	((p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])))
		rrr(p, 1);
 	else if (p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])
		rra(p, 0);
 	else if (p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1])
		rrb(p, 0);
}

int	all_cmd_both(t_p *p)
{

	if (  (p->pa[0] < find_val_med(p, 2)) && (p->pb[0] >= find_val_med_in_b(p, 2)) )
		rrr(p, 1);
	else if ( !(p->pa[0] < find_val_med(p, 2))  && !(p->pb[0] >= find_val_med_in_b(p, 2)) )
		rr(p, 1);
	else
		return (ERROR);
	return (SUCCESS);
}

void	bef_val_med_in_a(t_p *p)
{
	int val_med;

	//val_med = find_val_med(p, 2);
	//printf("VM = [%d]\n", val_med);
	while (pa_is_trim(p) == ERROR && is_sort(p) == ERROR)
	{
		//all_cmd_both(p);
		val_med = find_val_med(p, 2);
		//printf("VM = [%d]\n", val_med);
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
		//rrotate(p);
	}
}

void	bef_val_med_in_b(t_p *p)
{
	int val_med;

	//val_med = find_val_med_in_b(p, 2);
	while (is_sort(p) == ERROR && pa_is_trim(p) != ERROR && p->lenb > 0)
	{
		//all_cmd_both(p);
		val_med = find_val_med_in_b(p, 2);
		//printf("VM-b = [%d]", val_med);
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
	char	*cmd;

	int r = 0;
	int med = ((p->lena + 1) / 2);
	int val_med = find_val_med(p, 2);
	//disp_st(p);
	while (is_sort(p) == ERROR)
	{
		//printf("[%d][%d]\n", pa_is_trim(p));
		if (pa_is_trim(p) == ERROR && p->lena != -1)
			bef_val_med_in_a(p);
		else if (pb_is_trim(p) == ERROR && p->lenb != -1)
			bef_val_med_in_b(p);
		else
			pa(p, 0);

		//sort_indiv(p);

		//if (pb_is_trim(p) != ERROR && pa_is_trim(p) != ERROR
		//&& p->lenb != -1 && p->lena != -1)
		//	pa(p, 0);
		///}
		//else
		//sort_indiv(p);

	}
/* 	while (is_sort(p) == ERROR)
	{

		//	if (r >= 0)
		//	r = median_algo(r, med, p);
		sort_indiv(p);
		//first_algo(p);

	} */

	//printf("i = [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}
