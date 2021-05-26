/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/26 18:07:28 by philippe         ###   ########.fr       */
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

/* int	pp_g_med2(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] < val_med)
			return (i);
		i++;
	}
	return (i);
}

int	pp_d_med2(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] < val_med)
			return (i);
		i++;
	}
	return (i);
} */

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


/* void fillpb_first_med(t_p *p, int div, int av)
{
	p->val_med_a = find_val_med(p, div);
	p->val_med_b = find_val_med_in_b(p, div);
	p->div = 1;
	while (no_val_med_in_a(p, p->val_med_a) == ERROR && pa_opti_fill(p) == ERROR && p->lena >= 0)
	{
		//p->val_med_b = find_val_med_in_b(p, div);
		if (p->pa[p->lena] < p->val_med_a)
			pb(p, 0);
		else if (pp_g_med2(p->pa, p->lena, p->val_med_a) < pp_d_med2(p->pa, p->lena, p->val_med_a))
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, p->val_med_a) == SUCCESS)
		{
			p->val_med_a = find_val_med(p, div);
			p->div++;
		}
	}
} */

void fillpb_first_med(t_p *p, int div, int av)
{
	p->val_med_a = find_val_med(p, div);
	p->val_med_b = find_val_med_in_b(p, div);
	p->div = 1;
	while (no_val_med_in_a(p, p->val_med_a) == ERROR && pa_opti_fill(p) == ERROR && p->lena >= 0)
	{
		//p->val_med_b = find_val_med_in_b(p, div);
		if (p->pa[p->lena] < p->val_med_a)
			pb(p, 0);
		else if (p->pa[0] < p->val_med_a)
			rra(p, 0);
		else
			ra(p, 0);
		if (no_val_med_in_a(p, p->val_med_a) == SUCCESS)
		{
			p->val_med_a = find_val_med(p, div);
			p->div++;
		}
	}
}

void	fillpa_sec_med(t_p *p, int div, int av)
{
	while (is_sort(p) == ERROR && p->lenb > 0 && pb_opti_fill(p) == ERROR && p->lena < av)
	{
		p->val_med_b = find_val_med_in_b(p, div);
		while (no_val_med_in_b(p, p->val_med_b) == ERROR && pb_opti_fill(p) == ERROR && p->lena < av)
		{
			p->val_med_a = find_val_med(p, div);
			if (p->pb[p->lenb] >= p->val_med_b)
				pa(p, 0);
			else if (pp_g(p->pb, p->lenb, p->val_med_b) <= pp_d(p->pb, p->lenb, p->val_med_b))
				rrb(p, 0);
			else
				rb(p, 0);
		}
	}
	//printf("[%d][%d]\n\n", p->lena, av);
}

void	fillpa_trim(t_p *p, int div, int av)
{
	p->val_med_a = find_val_med(p, div);
	p->val_med_b = next_val_med_pb(p, p->val_med_a);

	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, p->val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR
	&& p->lena < av)
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


void	fillpb_trim_neg(t_p *p, int div, int av)
{
	p->val_med_a = next_val_med_pa(p);
	//printf("VM [%d]\n", p->val_med_a);
	//printf("[%d][%d][%d]\n",no_val_egg_in_a(p, p->val_med_a), p->lena,
	//pa_opti_fill(p));

	while (p->lena >= 0 && pa_opti_fill(p) == ERROR && p->lena < av)
	{
		//printf("VM [%d]\n", p->val_med_a);
		if (p->pa[p->lena] == p->val_med_a)
		{
			pb(p, 0);
			p->val_med_a = next_val_med_pa(p);
		}
		else if (pp_g_med(p->pa, p->lena, p->val_med_a) <= pp_d_med(p->pa, p->lena, p->val_med_a))
		{
					//	printf("IIIIICCCCCIIII22222222 [%d] [%d]  [%d] \n",
		//pp_g_med(p->pa, p->lena, p->val_med_a),pp_d_med(p->pa, p->lena, p->val_med_a), p->val_med_a);

				rra(p, 0);
		}
		else
		{
		//	printf("IIIIICCCCCIIII\n");

			ra(p, 0);
		}
	}
//	printf("[%d][%d]\n",p->lena, pa_opti_fill(p));

}

int	long_loop(t_p *p)
{
	p->init_med = find_val_med(p, 2);
	p->val_med_a = find_val_med(p, 2);
	p->val_med_b = next_val_med_pb(p, p->val_med_a);
	p->div = 0;
	p->init_lena = p->lena;

	fillpb_first_med(p, 2, 0);

	//p->div++;
	while (p->div >= 1 && is_sort(p) == ERROR)
	{
		fillpa_trim(p, 2,(p->init_lena / p->div));
		if (p->div > 1)
			p->div--;
		fillpa_sec_med(p, 2, (p->init_lena / p->div));
		printf("--[%d]--\n", (p->init_lena / p->div));

		if (p->div > 1)
			p->div--;
		fillpb_trim_neg(p, 2, p->init_lena);
		printf("--[%d]--\n", (p->init_lena / p->div));

		if (p->div > 1)
			p->div--;
		fillpa_trim(p, 2,(p->init_lena / p->div));
		printf("--[%d]--\n", (p->init_lena / p->div));

		if (p->div > 1)
			p->div--;
		fillpa_sec_med(p, 2, (p->init_lena / p->div));
		printf("--[%d]--\n", (p->init_lena / p->div));

		if (p->div > 1)
			p->div--;
		fillpb_trim_neg(p, 2, p->init_lena);
		printf("--[%d]--\n", (p->init_lena / p->div));
		if (p->div > 1)
			p->div--;
		printf("--[%d]--\n", (p->init_lena / p->div));
	}

	//printf ("div = [%d] i = [%d]\n", p->div, p->count);
	//fillpa_sec_med(p, 3, 0);
	//fillpb_first_med(p, 3, 0);

/* 	fillpb_first_med(p, 3, 1);
	fillpa_sec_med(p, 3, 1);
	fillpb_first_med(p, 3, 1); */


	//fillpa_trim_pos(p, 3);
	
	//fillpb_first_med(p, 3, 0);
	
//	fillpa_trim(p, 3);
	//conter le nombre de div pour les repeter dans le b
	printf("i = [%d] len = [%d] div = [%d]\n", p->count, p->init_med, p->div);
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
