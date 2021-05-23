/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/23 16:38:13 by phbarrad         ###   ########.fr       */
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
	int	val_med;

	val_med = find_val_med(p);
	//printf("VM = [%d]\n", val_med);
	while (is_sort(p) == ERROR)
	{
		//all_cmd_both(p);
		sswap2(p);
		val_med = find_val_med(p);
		//printf("VM = [%d]\n", val_med);
		while (no_val_med_in_a(p, val_med) == ERROR && p->lena >= 0 && pa_opti_fill(p) == ERROR)
		{
			//printf("opti = [%d]\n", pa_opti_fill(p));
			if (p->pa[p->lena] < val_med)
				pb(p, 0);
			else if (p->pa[0] < val_med)
				rra(p, 0);
			else
				ra(p, 0);
			if (no_val_med_in_a(p, val_med) == SUCCESS)
				val_med = find_val_med(p);
			//printf("VM = [%d]\n", val_med);
			sswap2(p);

		}
		//printf("opt[%d]\n",pa_opti_fill(p));
		val_med = find_val_med_in_b(p);
		//printf("VM-b = [%d]\n", val_med);
		sswap2(p);

		while (no_val_med_in_b(p, val_med) == ERROR && p->lenb >= 0 && pb_opti_fill(p) == ERROR)
		{
			//printf("VM-b = [%d]\n", val_med);

			if (p->pb[p->lenb] >= val_med)
				pa(p, 0);
			else if (p->pb[0] >= val_med)
				rrb(p, 0);
			else
				rb(p, 0);
			if (no_val_med_in_b(p, val_med) == SUCCESS)
				val_med = find_val_med_in_b(p);
			sswap2(p);
		}
		while (pb_opti_fill(p) != ERROR && pa_opti_fill(p) != ERROR && is_sort(p) == ERROR)
			pa(p, 0);
	}
/*		while (is_sort(p) == ERROR)
		{

			while (pa_is_trim(p) == SUCCESS && is_sort(p) == ERROR)
			{
				val_med = find_val_med_in_b(p);
				//printf("VM-b = [%d]", val_med);

				while (no_val_med_in_b(p, val_med) == ERROR && p->lenb >= 0 && pa_is_trim(p) == SUCCESS && is_sort(p) == ERROR)
				{
					if (p->pb[p->lenb] >= val_med)
						pa(p, 0);
					else if (p->pb[0] >= val_med)
						rrb(p, 0);
					else
						rb(p, 0);
					if (no_val_med_in_b(p, val_med) == SUCCESS)
						val_med = find_val_med_in_b(p);
				}
			}
			sswap2(p);
			val_med = find_val_med(p);
			while (pa_is_trim(p) != SUCCESS && is_sort(p) == ERROR)
			{
				if (p->pa[p->lena] < val_med)
					pb(p, 0);
				else if (p->pa[0] < val_med)
					rra(p, 0);
				else
					ra(p, 0);
			}
		}*/

		//while (pb_is_trim(p) != ERROR && pa_is_trim(p) != ERROR)
		//	pa(p, 0);

/*


		val_med = find_val_med(p);
		//printf("VM = [%d]\n", val_med);
		//sswap2(p);
		while (pa_is_trim(p) == ERROR && p->lena > 0)
		{
			if (p->pa[p->lena] < val_med)
				pb(p, 0);
			else if (p->pa[0] < val_med)
				rra(p, 0);
			else
				ra(p, 0);
			if (no_val_med_in_a(p, val_med) == SUCCESS)
				val_med = find_val_med(p);
			//sswap2(p);

		}

		val_med = find_val_med_in_b(p);
		printf("VM-b = [%d]", val_med);
		while (pb_is_trim(p) == ERROR)
		{
			if (p->pb[p->lenb] > val_med)
				pa(p, 0);
			else if (p->pb[0] > val_med)
				rrb(p, 0);
			else
				rb(p, 0);
			if (no_val_med_in_b(p, val_med) == SUCCESS)
				val_med = find_val_med_in_b(p);
		}
		while (pb_is_trim(p) != ERROR && pa_is_trim(p) != ERROR)
			pa(p, 0);*/
	//}
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
		//sswap2(p);
		while (no_val_med_in_b(p, val_med) == ERROR)
		{
			if (p->pb[p->lenb] >= val_med)
				pa(p, 0);
			else if (p->pb[0] >= val_med)
				rrb(p, 0);
			else
				rb(p, 0);
			//sswap2(p);
		}
	}
}

int	long_loop(t_p *p)
{
	char	*cmd;

	int r = 0;
	int med = ((p->lena + 1) / 2);
	int val_med = find_val_med(p);
	//printf("val med = [%d]\n", val_med);
	//disp_st(p);
	//while (is_sort(p) == ERROR)
	//{
		//printf("[%d][%d]\n", pa_is_trim(p));
		if (pa_is_trim(p) == ERROR && p->lena != -1)
			bef_val_med_in_a2(p);
	//	else if (pb_is_trim(p) == ERROR && p->lenb != -1)
		//	bef_val_med_in_b2(p);
	//	else
	//		pa(p, 0);

		//sort_indiv(p);

		//if (pb_is_trim(p) != ERROR && pa_is_trim(p) != ERROR
		//&& p->lenb != -1 && p->lena != -1)
		//	pa(p, 0);
		///}
		//else
		//sort_indiv(p);

//	}


	//printf("i = [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}


/*		while (is_sort(p) == ERROR)
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
		}*/
