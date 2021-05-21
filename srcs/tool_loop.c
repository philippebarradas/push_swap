/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:09:58 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/21 19:11:51 by philippe         ###   ########.fr       */
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