/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:39:50 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/22 13:45:09 by philippe         ###   ########.fr       */
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
	return ;
	if (p->lena > p->lenb)
		max = p->lena;
	else
		max = p->lenb;
	int r = max;
	//ft_putstr_fd("\033c", STDOUT);
	ft_putstr_fd("\n\n", STDOUT);

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
			while (++e <= p->pb[max])
				ft_putstr_fd("+", STDOUT);
			while (--e >= p->pb[max] && p->pb[max] < 0)
				ft_putstr_fd("-", STDOUT);
			e = 0;
			ft_putstr_fd(" ", STDOUT);
			ft_putnbr_fd(p->pb[max], STDOUT);
		}
		else
			ft_putstr_fd("o", STDOUT);
		printf("\n");
		max--;
	}
	usleep(80000);
	printf("\n\n");
}

void	rrr(t_p *p, int x)
{
	rra(p, 1);
	rrb(p, 1);
	ft_putstr_fd_count("rrr\n", STDOUT, p);
}
