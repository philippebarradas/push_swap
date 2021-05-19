/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:34:43 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/19 14:38:37 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_bonus.h"

void	ffree(void *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_all(t_p *p)
{
	ffree(p->pa);
	ffree(p->pb);
	free(p);
}

void	disp_st( t_p *p)
{
	int	i;
	int	max;

	if (p->lena > p->lenb)
		max = p->lena;
	else
		max = p->lenb;
	while (max >= 0)
	{
		if (p->lena >= max)
			printf("a = [%d]", p->pa[max]);
		else
			printf("a = [ ]");
		if (p->lenb >= max)
			printf("               b = [%d]", p->pb[max]);
		else
			printf("               b = [ ]");
		printf("\n");
		max--;
	}
	printf("\n\n");
}

void	rrr(t_p *p)
{
	rra(p);
	rrb(p);
}
