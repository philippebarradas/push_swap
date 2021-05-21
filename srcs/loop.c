/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/21 20:33:15 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

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

int	min_is_in_pa(t_p *p, int min)
{
	int	r;

	r = 0;
	while (r <= p->lena)
	{
		if (min == p->pa[r])
		{
			printf("min = [%d]\n", p->pa[r]);
			return (SUCCESS);
		}
		r++;
	}
	return (ERROR);
}

int find_val_med(t_p *p)
{
	int i;
	int max;
	int min;
	int e = 0;

	max = p->pa[i];
	min = p->pa[i];
	i = 0;
	while (i <= p->lena)
	{
		printf("[%d]\n", p->pa[i]);
		if (p->pa[i] > max)
			max = p->pa[i];
		if (p->pa[i] < min)
			min = p->pa[i];
		i++;
	}
	printf("max = [%d] min = [%d]\n", max, min);
	while (e < ((p->lena) / 2) && min < max)
	{
		if (min_is_in_pa(p, min) == SUCCESS)
			e++;
		min++;
	}
	printf("res = [%d] ned = [%d]\n", min, ((p->lena) / 2));
	return (min);
}

int	loop(t_p *p)
{
	char	*cmd;

	int r = 0;
	int med = ((p->lena + 1) / 2);
	int val_mec = find_val_med(p);
	//disp_st(p);
	while (is_sort(p) == ERROR)
	{
		//	if (r >= 0)
		//	r = median_algo(r, med, p);
		//sort_indiv(p);
		//first_algo(p);
	
	}
	 
	printf("i = [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}
