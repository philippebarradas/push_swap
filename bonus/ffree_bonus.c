/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:34:43 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/20 11:20:04 by phbarrad         ###   ########.fr       */
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

void	disp_st( t_p *p, char *str)
{
	int	i;
	int	max;
	int e = 0;
	if (p->lena > p->lenb)
		max = p->lena;
	else
		max = p->lenb;
	int r = max;
	while (max >= 0)
	{
		if (p->lena >= max)
		{
			while (++e <= p->pa[max] && p->pa[max] > 0)
				ft_putstr_fd("+", STDOUT);
			while (--e >= p->pa[max] && p->pa[max] < 0)
				ft_putstr_fd("-", STDOUT);
			if (e < 0)
				e = e * -1;
		}
		else
		{
			e = 1;
			ft_putstr_fd("o", STDOUT);
		}
		while (++e <= p->max)
			ft_putstr_fd(" ", STDOUT);
		e = 0;
		if (p->lenb >= max)
		{
			while (++e <= p->pb[max])
				ft_putstr_fd("+", STDOUT);
			while (--e >= p->pb[max] && p->pb[max] < 0)
				ft_putstr_fd("-", STDOUT);
			e = 0;
			//printf("               b = [%d]", p->pb[max]);
		}
		else
			ft_putstr_fd("o", STDOUT);
		printf("\n");
		max--;
	}
	usleep(200);
	printf("\n\n");
}

void	rrr(t_p *p)
{
	rra(p);
	rrb(p);
}
