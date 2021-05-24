/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/24 13:21:23 by phbarrad         ###   ########.fr       */
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
/*void	sswap2(t_p *p)
{
	if ((p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])&&
	(p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1]))
		ss(p, 1);
	else if(p->lena >= 1 && p->pa[p->lena] > p->pa[p->lena - 1])
		sa(p, 0);
	else if (p->lenb >= 1 && p->pb[p->lenb] < p->pb[p->lenb - 1])
		sb(p, 0);
}
*/

int	long_loop(t_p *p)
{
	int	val_med_a;
	int val_med_b;
	int	init_med;

	init_med = find_val_med(p);
	val_med_a = find_val_med(p);
	val_med_b = find_val_med_in_b(p);
		//printf("VM = [%d]\n", val_med);
	while (no_val_med_in_a(p, val_med_a) == ERROR && p->lena >= 0 && pa_opti_fill(p) == ERROR)
	{
			//printf("opti = [%d]\n", pa_opti_fill(p));
		val_med_b = find_val_med_in_b(p);
		if (p->pa[p->lena] < val_med_a)
			pb(p, 0);
		else if (p->pa[0] < val_med_a)
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, val_med_a) == SUCCESS)
			val_med_a = find_val_med(p);
		//printf("VM = [%d]\n", val_med);
	}
	//	printf("VM-b4 = [%d]\n\n", val_med[e]);
	val_med_b = next_val_med_pb(p, val_med_a);
	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR && val_med_b >= init_med)
	{
		//sswap2(p);
		//printf("VM-b = [%d]\n", val_med[e]);
		if (p->pb[p->lenb] >= val_med_b)
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
		//all_cmd_both(p);
		val_med_b = find_val_med_in_b(p);
		//printf("VM-b = [%d]", val_med);
		//sswap(p);
		while (no_val_med_in_b(p, val_med_b) == ERROR)
		{
			if (p->pb[p->lenb] >= val_med_b)
				pa(p, 0);
			else if (p->pb[0] >= val_med_b)
				rrb(p, 0);
			else
				rb(p, 0);
			//sswap(p);
		}
	}

	val_med_a = find_val_med(p);
	//printf("VM = [%d]\n", val_med);
	while (no_val_med_in_a(p, val_med_a) == ERROR && p->lena >= 0 && pa_opti_fill(p) == ERROR)
	{
		//printf("opti = [%d]\n", pa_opti_fill(p));
		if (p->pa[p->lena] < val_med_a)
			pb(p, 0);
		else if (p->pa[0] < val_med_a)
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, val_med_a) == SUCCESS)
			val_med_a = find_val_med(p);
		//printf("VM = [%d]\n", val_med);
	}
		//printf("VM-b4 = [%d]\n\n", val_med[i]);
	val_med_b = next_val_med_pb(p, val_med_a);
	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR)
	{
		//sswap2(p);
		//printf("VM-b = [%d]\n", val_med[e]);
		if (p->pb[p->lenb] >= val_med_b)
			pa(p, 0);
		else if (pp_g(p->pb, p->lenb, val_med_b) <= pp_d(p->pb, p->lenb, val_med_b))
			rrb(p, 0);
			else
			rb(p, 0);
		if (no_val_med_in_b(p, val_med_b) == SUCCESS)
			val_med_b = next_val_med_pb(p, val_med_b);
	}
	while (pb_opti_fill(p) != ERROR && pa_opti_fill(p) != ERROR && is_sort(p) == ERROR)
		pa(p, 0);
	//printf("i = [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}
