/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:39:50 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/07 15:33:59 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

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
	int e = 0;
	//sreturn ;
	if (p->lena > p->lenb)
		max = p->lena;
	else
		max = p->lenb;
	int r = max;

	printf("\n\n\n\n\n\n\n");
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
			ft_putstr_fd(" ", STDOUT);
			ft_putnbr_fd(p->pa[max], STDOUT);
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
			if (p->pb[max] == p->max_b)
				ft_putstr_fd("\033[0;32m", STDOUT);
			if (p->pb[max] == p->min)
				ft_putstr_fd("\033[0;36m", STDOUT);
			while (++e <= p->pb[max])
				ft_putstr_fd("+", STDOUT);
			while (--e >= p->pb[max] && p->pb[max] < 0)
			{	
				//if (p->pb[max] != p->max_b)
				//	ft_putstr_fd("\033[0;31m", STDOUT);
				ft_putstr_fd("-", STDOUT);
				//if (p->pb[max] != p->max_b)
				//	ft_putstr_fd("\033[0m", STDOUT);
			}
			e = 0;
			ft_putstr_fd(" ", STDOUT);
			ft_putnbr_fd(p->pb[max], STDOUT);
			if (p->pb[max] == p->max_b || p->pb[max] == p->min)
				ft_putstr_fd("\033[0m", STDOUT);
		}
		else
			ft_putstr_fd("o", STDOUT);
		printf("\n");
		max--;
	}
	usleep(60000);
}

void	rrr(t_p *p, int x)
{
	rra(p, 1);
	rrb(p, 1);
	ft_putstr_fd_count("rrr\n", STDOUT, p);
}
