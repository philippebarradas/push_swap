/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/08 14:38:02 by phbarrad         ###   ########.fr       */
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
		if (p->pa[e] < reta && p->pa[e] > p->min)
			reta = p->pa[e];
		e++;
	}
	e = 0;
	retb = p->max;
	while (e <= p->lenb)
	{
		if (p->pb[e] < retb && p->pb[e] > p->min)
			retb = p->pb[e];
		e++;
	}
	if (reta < retb)
		return (reta);
	return (retb);
}

void	fillpb_first_med(t_p *p, float av, int len)
{
	while (pa_opti_fill(p) == ERROR && p->lena >= 0 && p->lena >= len)
	{
		if (p->pa[p->lena] < p->val_med_a)
			pb(p, 0);
		else if (p->pa[0] < p->val_med_a && p->pa[0] < p->pa[p->lena - 1])
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, p->val_med_a) == SUCCESS)
			p->val_med_a = find_val_med(p, av);
	}
}

void	fillpa_sec_med(t_p *p, float av, int len)
{
	int e = 0;//5
	while (p->lenb >= 0 && p->lenb >= len && pb_opti_fill(p) == ERROR) 
	{
		p->val_med_a = find_val_med(p, 3);
		if (p->pb[p->lenb] >= p->val_med_b)
		{
			pa(p, 0);
			if (p->pa[p->lena] == p->min)
			{
				ra(p, 0);
				p->min = next_min(p);
			}
		}
		else if (p->pb[p->lenb] > p->pb[p->lenb - 1] && p->pa[p->lena] > p->pa[p->lena - 1])
			ss(p, 1);
		else if (pp_g(p->pb, p->lenb, p->val_med_b) == pp_d(p->pb, p->lenb, p->val_med_b)
		&& pp_g_val(p->pb, p->lenb, p->val_med_b) > pp_d_val(p->pb, p->lenb, p->val_med_b))
		{
			//printf(" ==== [%d] == [%d] ==== \n" ,pp_g_val(p->pb, p->lenb, p->val_med_b), pp_d_val(p->pb, p->lenb, p->val_med_b));
			rrb(p, 0);
			//break;
			//p->lenb = -1;
		}
		else if (pp_g(p->pb, p->lenb, p->val_med_b) < pp_d(p->pb, p->lenb, p->val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		if (no_val_med_in_b(p, p->val_med_b) == SUCCESS)
		{
			e++;
			p->val_med_b = find_val_med_in_b(p, av);
		}
	}
}

void	find_max_b(t_p *p)
{
	int i;
	int max;
	if (p->lenb == -1)
	{
		max = 0;
		return ; 
	}
	max = p->pb[0];
	i = 0;
	while (i <= p->lenb)
	{
		if (p->pb[i] > max)
			max = p->pb[i];
		i++;
	}
	p->max_b = max;
	//printf("max b = [%d]\n", max);
}

int	long_loop(t_p *p)
{
	p->div = 0;
	p->init_lena = p->lena;
	int initmin = p->min;
	p->init_med = find_val_med(p, 2);
	int r = 0;
  	int mi;
   	int ma;
	if (p->lena < 200)
	{
			 p->val_med_a = find_val_med(p, 2);
	 fillpb_first_med(p, 2, p->init_lena / 4);
   	    p->val_med_b = find_val_med_in_b(p, 6);
	   fillpa_sec_med(p, 3, p->init_lena / 2);
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
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb, next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)) )
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		}
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] == p->max_b && p->lenb >= 1)
			pa(p, 0);
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] != p->min)
		{
			if (pp_g_egg(p->pb, p->lenb, p->min) <= pp_d_egg(p->pb, p->lenb, p->min))
				mi = pp_g_egg(p->pb, p->lenb, p->min);
			else 
				mi = pp_d_egg(p->pb, p->lenb, p->min);
			if (pp_g_egg(p->pb, p->lenb, p->max_b) <= pp_d_egg(p->pb, p->lenb, p->max_b)) 
				ma = pp_g_egg(p->pb, p->lenb, p->max_b);
			else 
				ma = pp_d_egg(p->pb, p->lenb, p->max_b);



			/* 	printf("min [%d] [%d][%d] = [%d]\nmax [%d] [%d][%d] = [%d]\n",
			mi, pp_g_egg(p->pb, p->lenb, p->min), pp_d_egg(p->pb, p->lenb, p->min), p->min,
			ma, pp_g_egg(p->pb, p->lenb, p->max_b), pp_d_egg(p->pb, p->lenb, p->max_b), p->max_b);
 			*/

			if ((pp_g_egg(p->pb, p->lenb, p->max_b) < pp_g_egg(p->pb, p->lenb, p->min) && mi > ma)
			|| (pp_g_egg(p->pb, p->lenb, p->min) < pp_g_egg(p->pb, p->lenb, p->max_b) && ma > mi))
				rrb(p, 0);
			else if (pp_d_egg(p->pb, p->lenb, p->min) < pp_d_egg(p->pb, p->lenb, p->max_b) && ma == mi && 1 == 1)
			{
				/* 			
				printf("min [%d] [%d][%d] = [%d]\nmax [%d] [%d][%d] = [%d]\n",
				mi, pp_g_egg(p->pb, p->lenb, p->min), pp_d_egg(p->pb, p->lenb, p->min), p->min,
				ma, pp_g_egg(p->pb, p->lenb, p->max_b), pp_d_egg(p->pb, p->lenb, p->max_b), p->max_b); */
 				rb(p, 0);
				//r = 1;
				//break;
				//p->lenb = -1;
			}
			else if (pp_d_egg(p->pb, p->lenb, p->min) > pp_d_egg(p->pb, p->lenb, p->max_b) && ma == mi && 1 == 1)
			{
				/* 				
				printf("min [%d] [%d][%d] = [%d]\nmax [%d] [%d][%d] = [%d]\n",
				mi, pp_g_egg(p->pb, p->lenb, p->min), pp_d_egg(p->pb, p->lenb, p->min), p->min,
				ma, pp_g_egg(p->pb, p->lenb, p->max_b), pp_d_egg(p->pb, p->lenb, p->max_b), p->max_b); */
 				rrb(p, 0);
				//r = 1;
				//break;
				//p->lenb = -1;
			}
			else
				rb(p, 0);
		}	
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] == p->min)
		{
			pa(p, 0);
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb, next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)))
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		}
		else if (is_in_pill(p->pa, p->min, p->lena) == SUCCESS)// find min in pa push other -> pb
			pb(p , 0);
	}
	//printf("i == [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}

/* 		else if (p->pa[p->lena - 1] == p->min && p->lena > 0)
		{
			if (p->pb[p->lenb - 1] < p->pb[p->lenb] && p->lenb > 0)
				ss(p, 1);
			else
				sa(p, 0);
			if (p->pb[p->lenb] != next_min(p) && pp_g_egg(p->pb, p->lenb, next_min(p)) > pp_d_egg(p->pb, p->lenb, next_min(p)) )
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
		} */






/* void	fillpa_trim(t_p *p , int av)
 {
 	p->val_med_b = next_val_med_pb(p, p->val_med_a);
 	while (no_val_med_in_b(p, p->val_med_b) == ERROR && p->lenb >= (av) && pb_opti_fill(p) == ERROR) //&& p->lena < av)
 	{
 		//printf("VM-b = [%d]\n", val_med[e]);
 		if (p->pb[p->lenb] >= p->val_med_b)
 			pa(p, 0);
 		else if (pp_g(p->pb, p->lenb, p->val_med_b) <= pp_d(p->pb, p->lenb, p->val_med_b))
 			rrb(p, 0);
 		else
 			rb(p, 0);
 		if (no_val_med_in_b(p, p->val_med_b) == SUCCESS)
 		{
 			p->val_med_b = next_val_med_pb(p, p->val_med_b);
 		}
 		//if (no_val_med_in_b(p, p->val_med_b) == SUCCESS)
 		//	p->val_med_b = next_val_med_pb(p, p->val_med_b);
 	}
 } */