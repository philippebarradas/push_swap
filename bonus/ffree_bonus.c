/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:34:43 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/23 16:42:23 by phbarrad         ###   ########.fr       */
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

void	rrr(t_p *p)
{
	rra(p);
	rrb(p);
}
