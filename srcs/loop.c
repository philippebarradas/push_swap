/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/20 17:35:15 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/push.h"

int	pa_is_trim(t_p *p)
{
	int	i;

	i = 0;
	while (i + 1 <= p->lena)
	{
		if (p->pa[i] < p->pa[i + 1])
		{
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	pb_top_is_min(t_p *p)
{
	int	i;

	i = 0;
    if (p->lenb == -1)
        return (ERROR);
	while (i <= p->lenb)
	{
		if (p->pb[p->lenb] > p->pb[i])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	pa_top_is_max(t_p *p)
{
	int	i;

	i = 0;
	while (i <= p->lena)
	{
		if (p->pb[0] < p->pa[i])
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	swap(t_p *p)
{
	if (p->pa[p->lena] > p->pa[p->lena - 1] && p->pb[p->lenb] < p->pb[p->lenb - 1]
		&& p->lena >= 1 && p->lenb >= 1)
	{
		ss(p);
		disp_st(p, "ss\n");
	}
	else if (p->pa[p->lena] > p->pa[p->lena - 1] && p->lena >= 1)
	{
		sa(p);
		disp_st(p, "sa\n");
	}
	else if (p->pb[p->lenb] < p->pb[p->lenb - 1] && p->lenb >= 1)
	{
		sb(p);
		disp_st(p, "sb\n");
	}
}

/*int		top_biggest_in_a(t_p *p)
{

}*/

void	rotate(t_p *p)
{
	if (p->pa[p->lena] < p->pa[p->lena - 1] && pa_is_trim(p) == ERROR)
	{
		pb(p);
		disp_st(p, "pb\n");
	}
	else if ((p->pa[p->lena] > p->pb[p->lenb] ||
	p->pa[p->lena - 1] > p->pb[p->lenb])&& p->lena != -1 && p->lenb != -1)
	{
		pa(p);
		disp_st(p, "pa\n");
	}
}

int	loop(t_p *p)
{
	char	*cmd;
	int	x;
	int y;
	int i;

	i = 0;
	x = p->lena;
	y = 0;
	int e;
	e = 0;
	//disp_st(p, "start\n");
	while (is_sort(p) == ERROR)
	{
		//swap
		if ((p->pa[p->lena] > p->pa[0] && p->pa[0] < p->pa[p->lena - 1]&& p->lena >= 1) &&
		((pb_top_is_min(p) == SUCCESS && p->lenb >= 1)))
		{
			rr(p);
			ft_putstr_fd("rr\n", STDOUT);
		}
		else if (p->pa[p->lena] > p->pa[0] && p->pa[0] < p->pa[p->lena - 1]&& p->lena >= 1)
		{
			ra(p);
			ft_putstr_fd("ra\n", STDOUT);
		}
		else if (pb_top_is_min(p) == SUCCESS && p->lenb >= 1)
		{
			rb(p);
			ft_putstr_fd("rb\n", STDOUT);
		}
		else if (  (p->pb[p->lenb] < p->pb[p->lenb - 1] && p->lenb >= 1) &&  ((p->pa[p->lena] > p->pa[p->lena - 1] && p->pa[0] > p->pa[p->lena - 1] && p->lena >= 1)
		|| (p->pa[p->lena] > p->pa[p->lena - 1] && p->lena == 1))  )
		{
			ss(p);
			ft_putstr_fd("ss\n", STDOUT);
		}
		else if (p->pb[p->lenb] < p->pb[p->lenb - 1] && p->lenb >= 1)
		{
			sb(p);
			ft_putstr_fd("sb\n", STDOUT);
		}
		else if ((p->pa[p->lena] > p->pa[p->lena - 1] && p->pa[0] > p->pa[p->lena - 1] && p->lena >= 1)
		|| (p->pa[p->lena] > p->pa[p->lena - 1] && p->lena == 1))
		{
			sa(p);
			ft_putstr_fd("sa\n", STDOUT);
		}
		else if (p->pa[p->lena] > p->pa[p->lena - 1] && p->pa[0] < p->pa[p->lena - 1] && p->lena >= 1)
		{
			rra(p);
			ft_putstr_fd("rra\n", STDOUT);
		}
		else if (p->pa[p->lena] < p->pa[p->lena - 1] && pa_is_trim(p) == ERROR)
		{
			pb(p);
			ft_putstr_fd("pb\n", STDOUT);
		}
		else if (pa_is_trim(p) == SUCCESS && p->lenb != -1 && is_sort(p) == ERROR)
		{
			pa(p);
			ft_putstr_fd("pa\n", STDOUT);
		}
		else if ((p->pa[p->lena] > p->pb[p->lenb] ||
		p->pa[p->lena - 1] > p->pb[p->lenb])&& p->lena != -1 && p->lenb != -1 && is_sort(p) == ERROR)
		{
			pa(p);
			ft_putstr_fd("pa\n", STDOUT);
		}
/*		rotate(p);
		//printf("v = [%d]\n", pb_top_is_min(p));
		if (pb_top_is_min(p) == SUCCESS && p->lenb >= 1)
		{
			rb(p);
			ft_putstr_fd("rb\n", STDOUT);
		}
		if (pa_top_is_max(p) == SUCCESS && p->lena >= 1)
		{
			ra(p);
			ft_putstr_fd("ra\n", STDOUT);
		}
		swap(p);*/


		//ft_putstr_fd("PAUSE\n", STDOUT);
		//i++;

	}
	//disp_st(p, "fin\n");
	//printf("\ni = [%d]\n\n", i);
	free(p);
	return (SUCCESS);
}


/*	while (is_sort(p) == ERROR)
	{
		//swap
		if (p->pa[p->lena] > p->pa[0] && p->pa[0] < p->pa[p->lena - 1]&& p->lena >= 1)
		{
			ra(p);
			ft_putstr_fd("ra\n", STDOUT);
		}
		else if (pb_top_is_min(p) == SUCCESS && p->lenb >= 1)
		{
			rb(p);
			ft_putstr_fd("rb\n", STDOUT);
		}
		else if (p->pb[p->lenb] < p->pb[p->lenb - 1] && p->lenb >= 1)
		{
			sb(p);
			ft_putstr_fd("sb\n", STDOUT);
		}
		else if ((p->pa[p->lena] > p->pa[p->lena - 1] && p->pa[0] > p->pa[p->lena - 1] && p->lena >= 1)
		|| (p->pa[p->lena] > p->pa[p->lena - 1] && p->lena == 1))
		{
			sa(p);
			ft_putstr_fd("sa\n", STDOUT);

		}
		else if (p->pa[p->lena] > p->pa[p->lena - 1] && p->pa[0] < p->pa[p->lena - 1] && p->lena >= 1)
		{
			rra(p);
			ft_putstr_fd("rra\n", STDOUT);
		}
		else if (p->pa[p->lena] < p->pa[p->lena - 1] && pa_is_trim(p) == ERROR)
		{
			pb(p);
			ft_putstr_fd("pb\n", STDOUT);
		}
		else if (pa_is_trim(p) == SUCCESS && p->lenb != -1 && is_sort(p) == ERROR)
		{
			pa(p);
			ft_putstr_fd("pa\n", STDOUT);
		}
		else if ((p->pa[p->lena] > p->pb[p->lenb] ||
		p->pa[p->lena - 1] > p->pb[p->lenb])&& p->lena != -1 && p->lenb != -1 && is_sort(p) == ERROR)
		{
			pa(p);
			ft_putstr_fd("pa\n", STDOUT);
		}
		rotate(p);
		//printf("v = [%d]\n", pb_top_is_min(p));
		if (pb_top_is_min(p) == SUCCESS && p->lenb >= 1)
		{
			rb(p);
			ft_putstr_fd("rb\n", STDOUT);
		}
		if (pa_top_is_max(p) == SUCCESS && p->lena >= 1)
		{
			ra(p);
			ft_putstr_fd("ra\n", STDOUT);
		}
		swap(p);


		//ft_putstr_fd("PAUSE\n", STDOUT);
		i++;

	}*/
