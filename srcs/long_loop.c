/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/22 16:42:21 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	all_cmd_both2(t_p *p)
{

	if (  (p->pa[0] < find_val_med(p)) && (p->pb[0] >= find_val_med_in_b(p)) )
		rrr(p, 1);	
	else if ( !(p->pa[0] < find_val_med(p))  && !(p->pb[0] >= find_val_med_in_b(p)) )
		rr(p, 1);
	else
		return (ERROR);	
	return (SUCCESS);
}

void	sswap2(t_p *p)
{
	if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])&&
	(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
		ss(p, 1);
	else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		sa(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
		sb(p, 0);
}

void	bef_val_med_in_a2(t_p *p)
{
	int val_med;

	//val_med = find_val_med(p);
	//printf("VM = [%d]\n", val_med);
	while (pa_is_trim(p) == ERROR && is_sort(p) == ERROR)
	{
		//all_cmd_both(p);
		val_med = find_val_med(p);
		//printf("VM = [%d]\n", val_med);
		sswap2(p);
		while (no_val_med_in_a(p, val_med) == ERROR && pa_is_trim(p) == ERROR)
		{
			if (p->pa[p->lena] < val_med)
				pb(p, 0);
			else if (p->pa[0] < val_med)
				rra(p, 0);
			else
				ra(p, 0);
			sswap2(p);

		}
		//rrotate(p);
	}
}

void	bef_val_med_in_b2(t_p *p)
{
	int val_med;

	//val_med = find_val_med_in_b(p);
	while (is_sort(p) == ERROR && pa_is_trim(p) != ERROR && p->lenb > 0)
	{
		//all_cmd_both(p);
		val_med = find_val_med_in_b(p);
		//printf("VM-b = [%d]", val_med);
		sswap2(p);
		while (no_val_med_in_b(p, val_med) == ERROR)
		{
			if (p->pb[p->lenb] >= val_med)
				pa(p, 0);
			else if (p->pb[0] >= val_med)
				rrb(p, 0);
			else
				rb(p, 0);
			sswap2(p);
		}
	}
}

int	long_loop(t_p *p)
{
	char	*cmd;

	int r = 0;
	int med = ((p->lena + 1) / 2);
	int val_med = find_val_med(p);
	//disp_st(p);
	while (is_sort(p) == ERROR)
	{
		//printf("[%d][%d]\n", pa_is_trim(p));
		if (pa_is_trim(p) == ERROR && p->lena != -1)
			bef_val_med_in_a2(p);
		else if (pb_is_trim(p) == ERROR && p->lenb != -1)
			bef_val_med_in_b2(p);
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

	 
	//printf("i = [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}
