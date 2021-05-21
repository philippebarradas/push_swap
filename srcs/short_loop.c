/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/21 19:40:04 by philippe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	short_loop(t_p *p)
{
	char	*cmd;

	int r = 0;
	int med = ((p->lena + 1) / 2);
	//disp_st(p);
	while (is_sort(p) == ERROR)
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
		else if (((p->lenb >= 1 && p->pb[0] > p->pa[p->lenb] && p->pa[0] > p->pa[p->lenb - 1]))
        && ((p->lena >= 1 && p->pa[0] < p->pa[p->lena] && p->pa[0] < p->pa[p->lena - 1])))
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
	//printf("i = [%d]\n", p->count);
	free(p);
	return (SUCCESS);
}