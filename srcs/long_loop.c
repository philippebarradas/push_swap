/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/03 16:26:33 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	next_val_med_pa(t_p *p)
{
	int e;
	int min;

	min = p->pa[p->lena];
	e = p->lena;
	while (e >= 0)
	{
		if (p->pa[e] < min)
			min = p->pa[e];
		e--;
	}
	return (min);
}

int	pp_g_med(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] <= val_med)
			return (i);
		i++;
	}
	return (i);
}

int	pp_d_med(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] <= val_med)
			return (i);
		i++;
	}
	return (i);
}

int		next_min(t_p *p)
{
	int e;
	int reta;
	int retb;

	e = 0;
	reta = p->max;
	while (e <= p->lena)
	{
	//	printf("[%d] < [%d] && [%d] > [%d]\n", p->pa[e] , reta ,p->pa[e] , p->min);
		if (p->pa[e] < reta && p->pa[e] > p->min)
			reta = p->pa[e];
		e++;
	}
//	printf("\n\n\n", reta);
	e = 0;
	retb = p->max;
	while (e <= p->lenb)
	{
		//printf("VM-b1 = [%d]\n", val_med);
		//printf("[%d] < [%d] && [%d] > [%d]\n", p->pb[e] , retb ,p->pb[e] , p->min);
		if (p->pb[e] < retb && p->pb[e] > p->min)
			retb = p->pb[e];
		e++;
	}
	//printf("reta = [%d] retb [%d]\n", reta, retb);
	if (reta < retb)
		return (reta);
	return (retb);
}

void	fillpb_first_med(t_p *p, int div, int av)
{
	int r;

	r = 0;
	while (pa_opti_fill(p) == ERROR && p->lena >= 0)
	{
		if (p->pa[p->lena] < p->val_med_a)
			pb(p, 0);
		else if (p->pa[0] < p->val_med_a)
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, p->val_med_a) == SUCCESS)
			p->val_med_a = find_val_med(p, av);
	}
}

void	fillpa_sec_med(t_p *p, int div, int av)
{
	p->val_med_b = find_val_med_in_b(p, div);
	while (pb_opti_fill(p) == ERROR && p->lenb >= 0)
	{
		if (p->pb[p->lenb] >= p->val_med_b)
		{
			pa(p, 0);
			if (p->pa[p->lena] == p->min)
			{
				ra(p, 0);
				p->min = next_min(p);
			}
		}
		else if (pp_g(p->pb, p->lenb, p->val_med_b) <= pp_d(p->pb, p->lenb, p->val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		if (no_val_med_in_b(p, p->val_med_b) == SUCCESS)
			p->val_med_b = find_val_med_in_b(p, av);
	}
}

int	long_loop(t_p *p)
{
	p->div = 0;
	p->init_lena = p->lena;
	int initmin = p->min;
	p->init_med = find_val_med(p, 2);

	if (p->lena < 200)
	{
		p->val_med_a = find_val_med(p, 2);
		fillpb_first_med(p, 2, 2);
		p->val_med_b = find_val_med_in_b(p, 2);
		fillpa_sec_med(p, 3, 2);
	}
	else if (p->lena >= 200)
	{
		p->val_med_a = find_val_med(p, 6);
		fillpb_first_med(p, 6, 3);
		p->val_med_b = find_val_med_in_b(p, 6);
		fillpa_sec_med(p, 6, 6);
	}
   
	while (is_sort(p) == ERROR && 1 == 1)
	{

		if (p->pa[p->lena] == p->min)
		{
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb, next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)) && p->lenb > 0 && p->lena > 0)
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		}
		else if (p->pa[p->lena - 1] == p->min && p->lena > 0)
		{
			if (p->pb[p->lenb - 1] < p->pb[p->lenb] && p->lenb > 0)
				ss(p, 1);
			else
				sa(p, 0);
		}
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] != p->min)
		{
/* 			if (p->pa[p->lena - 1] == p->min && p->lena > 0)
			{
				if (p->pb[p->lenb - 1] < p->pb[p->lenb] && p->lenb > 0)
					ss(p, 1);
				else
					sa(p, 0);
			}
			else  */
			if (pp_g_egg(p->pb, p->lenb, p->min) <= pp_d_egg(p->pb, p->lenb, p->min))
				rrb(p, 0);
			else
				rb(p, 0);
		}	
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] == p->min)
		{
			pa(p, 0);
/* 			if (p->pa[p->lena - 1] == p->min && p->lena > 0)
			{
				if (p->pb[p->lenb - 1] < p->pb[p->lenb] && p->lenb > 0)
					ss(p, 1);
				else
					sa(p, 0);
			}
			else  */
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb, next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
			//printf("2min = [%d][%d]\n",initmin, p->min);
		}
		else if (is_in_pill(p->pa, p->min, p->lena) == SUCCESS) // find min in pa push other -> pb
		{
			pb(p , 0);
		}
		
	}
	//printf("i == [%d]\n", p->count);
	free(p);
	return (SUCCESS);


}
