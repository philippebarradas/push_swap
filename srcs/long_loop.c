/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/31 16:34:31 by phbarrad         ###   ########.fr       */
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

int		next_min(t_p *p)
{
	int e;
	int reta;
	int retb;

	e = 0;
	reta = p->min + 10;
	while (e <= p->lena)
	{
	//	printf("[%d] < [%d] && [%d] > [%d]\n", p->pa[e] , reta ,p->pa[e] , p->min);
		if (p->pa[e] < reta && p->pa[e] > p->min)
			reta = p->pa[e];
		e++;
	}
//	printf("\n\n\n", reta);
	e = 0;
	retb = p->min + 10;
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
	p->val_med_a = find_val_med(p, div);
	//p->val_med_b = find_val_med_in_b(p, div);
	p->div = 1;
	while (no_val_med_in_a(p, p->val_med_a) == ERROR && pa_opti_fill(p) == ERROR && p->lena >= 0)
	{
		//printf("med = [%d]\n", p->val_med_a);
		//p->val_med_b = find_val_med_in_b(p, div);
		//printf("min = [%d]\n", p->min);
		if (p->pa[p->lena] < p->val_med_a)
		{
/*				if (p->pa[p->lena] == p->min)
				{
					ra(p, 0);
					p->min = next_min(p);
				}
				else*/
					pb(p, 0);
		}
		else if (p->pa[0] < p->val_med_a)// && p->pa[0] >= p->min)
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
	while (is_sort(p) == ERROR && p->lenb > 0)// && p->lena < av)
	{
		p->val_med_b = find_val_med_in_b(p, div);
		while (no_val_med_in_b(p, p->val_med_b) == ERROR)//&& p->lena < av)
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
		}
	}
	//printf("[%d][%d]\n\n", p->lena, av);
}

void	fillpa_trim(t_p *p, int div, int av)
{
	p->val_med_b = find_val_med_in_b(p, p->val_med_a);
	//printf("\nVM-b2 = [%d]\n", val_med[e]);
	while (no_val_med_in_b(p, p->val_med_b) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR) //&& p->lena < av)
	{
		if (p->pb[p->lenb] >= p->val_med_b)
			pa(p, 0);
		else if (pp_g(p->pb, p->lenb, p->val_med_b) <= pp_d(p->pb, p->lenb, p->val_med_b))
			rrb(p, 0);
		else
			rb(p, 0);
		//if (no_val_med_in_b(p, p->val_med_b) == SUCCESS)
		//	p->val_med_b = next_val_med_pb(p, p->val_med_b);
	}
	//printf("VM-b = [%d]\n", p->val_med_b);

	//while (pb_opti_fill(p) != ERROR && pa_opti_fill(p) != ERROR && is_sort(p) == ERROR)
	//	pa(p, 0);
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
	p->init_med = find_val_med(p, 3);
	p->val_med_a = find_val_med(p, 3);
	p->val_med_b = next_val_med_pb(p, p->val_med_a);
	p->div = 0;
	p->init_lena = p->lena;
	int initmin = p->min;

	if (p->lena < 200)
	{
		fillpb_first_med(p, 2, 0);
		fillpa_sec_med(p, 3, 0);
	}
	if (p->lena >= 200)
	{
		fillpb_first_med(p, 3, 0);
		fillpa_sec_med(p, 6, 0);
	}
	//printf("min = [%d][%d]\n",initmin, p->min);

	while (is_sort(p) == ERROR && 1 == 1)
	{
		if (p->pa[p->lena] == p->min) // min fin pa
		{
			if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] != p->min)
				rr(p, 1);
			else
				ra(p, 0);
			p->min = next_min(p);
			//printf("1min = [%d][%d]\n",initmin, p->min);
		}
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] == p->min) // min debut pb -> pa fin
		{
			pa(p, 0);
			ra(p, 0);
			p->min = next_min(p);
			//printf("2min = [%d][%d]\n",initmin, p->min);
		}
		else if (is_in_pill(p->pb, p->min, p->lenb) == SUCCESS && p->pb[p->lenb] != p->min) // find min in pb
		{
		//	printf("[%d] <= [%d] |||| %d\n", pp_g_egg(p->pb, p->lenb, p->min), pp_d_egg(p->pb, p->lenb, p->min), p->min);
			if (pp_g_egg(p->pb, p->lenb, p->min) <= pp_d_egg(p->pb, p->lenb, p->min))
				rrb(p, 0);
			else
				rb(p, 0);
		}
		else if (is_in_pill(p->pa, p->min, p->lena) == SUCCESS) // find min in pa push other -> pb
		{
			pb(p , 0);
			//printf("3min = [%d][%d]\n",initmin, p->min);
		}
		//printf("[%d][%d][%d]\n", is_in_pill(p->pa, p->min, p->lena), p->lena, p->min);


	}
	printf("i = [%d] len = [%d] div = [%d]\n", p->count, p->init_med, p->div);

	//while (pb_opti_fill(p) != ERROR && pa_opti_fill(p) != ERROR && is_sort(p) == ERROR)
	//	pa(p, 0);
	free(p);
	return (SUCCESS);


}
