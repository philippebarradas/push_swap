/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:23:21 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/08 10:06:19 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int	next_val_med_pb(t_p *p, int val_med)
{
	int e;

	e = 0;
	while (val_med >= p->min)
	{
		//printf("VM-b1 = [%d]\n", val_med);
		while (e <= p->lenb)
		{
			if (val_med == p->pb[e])
				return (val_med);
			e++;
		}
		e = 0;
		val_med--;
	}
	return (val_med);
}

int	pp_g_val(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] >= val_med)
			return (pill[i]);
		i++;
	}
	return (i);
}

int	pp_d_val(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] >= val_med)
			return (pill[len - i]);
		i++;
	}
	return (i);
}


int	pp_g(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] >= val_med)
			return (i);
		i++;
	}
	return (i);
}

int	pp_d(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] >= val_med)
			return (i);
		i++;
	}
	return (i);
}


int	pp_g_egg(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (pill[i] == val_med)
			return (i);
		i++;
	}
	return (i);
}

int	pp_d_egg(int *pill, int len, int val_med)
{
	int i;

	i = 0;
	while (len - i > 0)
	{
		if (pill[len - i] == val_med)
			return (i);
		i++;
	}
	return (i);
}
