/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/22 16:36:36 by philippe         ###   ########.fr       */
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

int	pb_is_trim(t_p *p)
{
	int	i;

	i = 0;
	while (i + 1 <= p->lenb)
	{
		//printf("[%d] > [%d]\n", p->pb[i], p->pb[i + 1]);
		if (p->pb[i] > p->pb[i + 1])
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

int	no_val_med_in_a(t_p *p, int val_med)
{
	int	i;

	i = 0;
	while (i <= p->lena)
	{
		if (p->pa[i] < val_med)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	no_val_med_in_b(t_p *p, int val_med)
{
	int	i;

	i = 0;
	while (i <= p->lenb)
	{
		if (p->pb[i] >= val_med)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}



int	min_is_in_pa(t_p *p, int min)
{
	int	r;

	r = 0;
	while (r <= p->lena)
	{
		if (min == p->pa[r])
		{
			//printf("min = [%d]\n", p->pa[r]);
			return (SUCCESS);
		}
		r++;
	}
	return (ERROR);
}

int find_val_med(t_p *p)
{
	int i;
	int max;
	int min;
	int e = 0;

	i = 0;
	max = p->pa[i];
	min = p->pa[i];
	while (i <= p->lena)
	{
		//printf("[%d]\n", p->pa[i]);
		if (p->pa[i] > max)
			max = p->pa[i];
		if (p->pa[i] < min)
			min = p->pa[i];
		i++;
	}
	//printf("max = [%d] min = [%d]\n", max, min);
	while (e <= ((p->lena) / 2) && min < max)
	{
		if (min_is_in_pa(p, min) == SUCCESS)
			e++;
		min++;
	}
	//printf("res = [%d] ned = [%d]\n", min, ((p->lena) / 2));
	return (min);
}

int	min_is_in_pb(t_p *p, int max)
{
	int	r;

	r = 0;
	while (r <= p->lenb)
	{
		if (max == p->pb[r])
		{
			//printf("min = [%d]\n", p->pa[r]);
			return (SUCCESS);
		}
		r++;
	}
	return (ERROR);
}

int find_val_med_in_b(t_p *p)
{
	int i;
	int max;
	int min;
	int e = 0;

	i = 0;
	max = p->pb[i];
	min = p->pb[i];
	while (i <= p->lenb)
	{
		//printf("[%d]\n", p->pb[i]);
		if (p->pb[i] > max)
			max = p->pb[i];
		if (p->pb[i] < min)
			min = p->pb[i];
		i++;
	}
//	printf("max = [%d] min = [%d]\n", max, min);
	while (e < ((p->lenb) / 2) && min < max)
	{
		max--;
		if (min_is_in_pb(p, max) == SUCCESS)
			e++;
	}
//	printf("res = [%d] ned = [%d] e = [%d]\n", min, ((p->lenb) / 2), e);
	return (max);
}