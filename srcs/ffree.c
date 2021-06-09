/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:39:50 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 14:48:14 by phbarrad         ###   ########.fr       */
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

void	rrr(t_p *p, int x)
{
	(void)x;
	rra(p, 1);
	rrb(p, 1);
	ft_putstr_fd_count("rrr\n", STDOUT, p);
}
