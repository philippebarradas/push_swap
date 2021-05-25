/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/25 14:56:04 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

/*int	all_cmd_both2(t_p *p)
{
	if ((p->pa[0] < find_val_med(p)) && (p->pb[0] >= find_val_med_in_b(p)) )
		rrr(p, 1);
	else if ( !(p->pa[0] < find_val_med(p))  && !(p->pb[0] >= find_val_med_in_b(p)) )
		rr(p, 1);
	else
		return (ERROR);
	return (SUCCESS);
}
*/
/*int	sswap2(t_p *p)
{
	if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1] && p->pa[p->lena - 1] < p->val_med_a)&&
	(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
	{
		ss(p, 1);
		return (SUCCESS);
	}
	return (ERROR);
	else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		sa(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
		sb(p, 0);
}*/

/*int	find_val_med_init(t_p *p, int div)
{
	int	i;
	int	max;
	int	min;
	int	e;

	e = 0;
	i = 0;
	max = p->pa[i];
	min = p->pa[i];
	while (i <= p->lena)
	{
		if (p->pa[i] > max)
			max = p->pa[i];
		if (p->pa[i] < min)
			min = p->pa[i];
		i++;
	}
	if ((p->lena % 2) == 1)
		e--;
	while (e < (p->lena / div) && min < max)
	{
		if (min_is_in_pa(p, min) == SUCCESS)
			e++;
		min++;
	}
	return (min);
}*/

void fillpb_first_med(t_p *p, int div)
{
	p->val_med_a = find_val_med(p, div);
	//p->val_med_b = next_val_med_pb(p, p->val_med_a);
	while (no_val_med_in_a(p, p->val_med_a) == ERROR && p->lena >= 0 && pa_opti_fill(p) == ERROR)
	{
		//p->val_med_b = next_val_med_pb(p, p->val_med_a);
		//printf("VM = [%d]\n", p->val_med_a);
		if (p->pa[p->lena] < p->val_med_a)
			pb(p, 0);
		else if (p->pa[0] < p->val_med_a)
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, p->val_med_a) == SUCCESS)
		{
		//	p->val_med_b = next_val_med_pb(p, p->val_med_a);
			p->val_med_a = find_val_med(p, div);
		}
		//printf("VM = [%d]\n", val_med);
	}
	//else if (pp_g(p->pb, p->lenb, val_med_b) > pp_d(p->pb, p->lenb, val_med_b))
	//	rr(p, 1);
}


void	fillpa_sec_med(t_p *p, int div)
{
	while (is_sort(p) == ERROR && p->lenb > 0 && pb_opti_fill(p) == ERROR)
	{
		p->val_med_b = find_val_med_in_b(p, div);
		p->val_med_a = find_val_med(p, div);
		while (no_val_med_in_b(p, p->val_med_b) == ERROR && pb_opti_fill(p) == ERROR)
		{
			if (p->pb[p->lenb] >= p->val_med_b)
				pa(p, 0);
			else if (pp_g(p->pb, p->lenb, p->val_med_b) <= pp_d(p->pb, p->lenb, p->val_med_b))
				rrb(p, 0);
			else
				rb(p, 0);
		}
	}
}

void	fillpb_last_med(t_p *p)
{

}

void	fillpa_trim(t_p *p, int div)
{
	p->val_med_a = find_val_med(p, div);
	p->val_med_b = next_val_med_pb(p, p->val_med_a);

	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, p->val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR)
	{
		p->val_med_a = find_val_med(p, div);
		//printf("VM-b = [%d]\n", val_med[e]);
		if (p->pb[p->lenb] >= p->val_med_b)
			pa(p, 0);
		else if (pp_g(p->pb, p->lenb, p->val_med_b) <= pp_d(p->pb, p->lenb, p->val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		if (no_val_med_in_b(p, p->val_med_b) == SUCCESS)
		{
			p->val_med_a = find_val_med(p, div);
			p->val_med_b = next_val_med_pb(p, p->val_med_b);
		}
	}
	while (pb_opti_fill(p) != ERROR && pa_opti_fill(p) != ERROR && is_sort(p) == ERROR)
		pa(p, 0);
}

void	fillpa_trim_pos(t_p *p, int div)
{
	p->val_med_a = find_val_med(p, div);
	p->val_med_b = next_val_med_pb(p, p->val_med_a);

	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, p->val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR && p->val_med_b >= (p->init_med))
	{
		p->val_med_a = find_val_med(p, div);
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
			p->val_med_a = find_val_med(p, div);
		}
	}
}

int	long_loop(t_p *p)
{
	p->init_med = find_val_med(p, 3);
	p->val_med_a = find_val_med(p, 3);
	p->val_med_b = next_val_med_pb(p, p->val_med_a);


	fillpb_first_med(p, 3);
	////fillpa_trim_pos(p);


	fillpa_sec_med(p, 3);
	fillpb_first_med(p, 3);
	fillpa_trim_pos(p, 3);

	fillpb_first_med(p, 3);
	fillpa_trim(p, 3);

	printf("i = [%d][%d]\n", p->count, p->init_med);
	free(p);
	return (SUCCESS);
/*	while (is_sort(p) == ERROR && p->lenb > 0 && pb_opti_fill(p) == ERROR)
	{
		val_med_b = find_val_med_in_b(p, 6);
		val_med_a = find_val_med(p, 6);
		while (no_val_med_in_b(p, val_med_b) == ERROR && pb_opti_fill(p) == ERROR)
		{
			if (sswap2(p) == SUCCESS)
				;
			else if (p->pb[p->lenb] >= val_med_b)
				pa(p, 0);
			else if (p->pb[0] >= val_med_b)
				rrb(p, 0);
			else
				rb(p, 0);
		}
	}

	val_med_a = find_val_med(p, 9);
	val_med_b = next_val_med_pb(p, val_med_a);
		//printf("VM = [%d]\n", val_med);
	while (no_val_med_in_a(p, val_med_a) == ERROR && p->lena >= 0 && pa_opti_fill(p) == ERROR)
	{
		//printf("opti = [%d]\n", pa_opti_fill(p));
		//val_med_b = find_val_med_in_b(p);

		val_med_b = next_val_med_pb(p, val_med_a);
		if (sswap2(p) == SUCCESS)
			;
		else if (p->pa[p->lena] < val_med_a)
			pb(p, 0);
		else if (p->pa[0] < val_med_a)
			rra(p, 0);
		else if (pp_g(p->pb, p->lenb, val_med_b) > pp_d(p->pb, p->lenb, val_med_b))
			rr(p, 1);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, val_med_a) == SUCCESS)
		{
			val_med_b = next_val_med_pb(p, val_med_a);
			val_med_a = find_val_med(p, 9);
		}
		//printf("VM = [%d]\n", val_med);
	}
*/

/*
	//	printf("VM- = [%d] [%d]\n\n", val_med_a, pa_opti_fill(p));
	val_med_b = next_val_med_pb(p, val_med_a);
	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR && (val_med_b) >= (init_med ))
	{
		val_med_a = find_val_med(p);
		//sswap2(p);
		//printf("VM-b = [%d]\n", val_med[e]);
		//printf("[%d][%d]\n", val_med_b, init_med);
		if (sswap2(p) == SUCCESS)
			;
		else if (p->pb[p->lenb] >= val_med_b)
			pa(p, 0);
		else if (pp_g(p->pb, p->lenb, val_med_b) <= pp_d(p->pb, p->lenb, val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		if (no_val_med_in_b(p, val_med_b) == SUCCESS)
			val_med_b = next_val_med_pb(p, val_med_b);
	}

	while (is_sort(p) == ERROR && p->lenb > 0 && pb_opti_fill(p) == ERROR)
	{
		val_med_b = find_val_med_in_b(p);
		val_med_a = find_val_med(p);
		while (no_val_med_in_b(p, val_med_b) == ERROR && pb_opti_fill(p) == ERROR)
		{
			if (sswap2(p) == SUCCESS)
				;
			else if (p->pb[p->lenb] >= val_med_b)
				pa(p, 0);
			else if (p->pb[0] >= val_med_b)
				rrb(p, 0);
			else
				rb(p, 0);
		}
	}

	val_med_a = find_val_med(p);
	val_med_b = next_val_med_pb(p, val_med_b);

	while (no_val_med_in_a(p, val_med_a) == ERROR && p->lena >= 0 && pa_opti_fill(p) == ERROR)
	{
		//printf("a[%d] b[%d]\n", val_med_a, val_med_b);
		val_med_b = next_val_med_pb(p, val_med_b);

		if (sswap2(p) == SUCCESS)
			;
		else if (p->pa[p->lena] < val_med_a && p->pa[p->lena] < init_med)
			pb(p, 0);
		else if (p->pa[0] < val_med_a)
			rra(p, 0);
		else if (pp_g(p->pb, p->lenb, val_med_b) > pp_d(p->pb, p->lenb, val_med_b))
			rr(p, 1);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, val_med_a) == SUCCESS)
		{
			val_med_b = next_val_med_pb(p, val_med_b);
			val_med_a = find_val_med(p);
		}
	}*/
	//printf("VM-b4 = [%d]\n\n", val_med[i]);
	/*val_med_b = next_val_med_pb(p, val_med_a);
	val_med_a = find_val_med(p, 12);

	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR)
	{
		val_med_a = find_val_med(p, 12);
		//printf("VM-b = [%d]\n", val_med[e]);
		if (sswap2(p) == SUCCESS)
			;
		else if (p->pb[p->lenb] >= val_med_b)
			pa(p, 0);
		else if (pp_g(p->pb, p->lenb, val_med_b) <= pp_d(p->pb, p->lenb, val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		if (no_val_med_in_b(p, val_med_b) == SUCCESS)
		{
			val_med_b = next_val_med_pb(p, val_med_b);
			val_med_a = find_val_med(p, 12);
		}
	}
	while (pb_opti_fill(p) != ERROR && pa_opti_fill(p) != ERROR && is_sort(p) == ERROR)
		pa(p, 0);*/

}
