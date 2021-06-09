/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_loop2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:17:27 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 13:18:07 by phbarrad         ###   ########.fr       */
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
			return (ERROR);
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
