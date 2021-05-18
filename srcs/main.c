/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:08:07 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/18 17:24:47 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push.h"

int		fill_pile(int ac, char **av, t_p *p)
{
	int i;
	int e;

	i = ac - 1;
	e = 1;
	p->lena = ac - 2;
	p->lenb = 0;
	p->pa = malloc(sizeof(int) * (ac - 1));
	if (!(p->pa))
		return (ERROR);
	p->pb = malloc(sizeof(int) * (ac - 1));
	if (!(p->pa))
		return (ERROR);
	while (i > 0)
	{
		p->pa[i - 1] = ft_atoi(av[e]);
		e++;
		i--;
	}

	i = -1;
	while (++i < ac - 1)
		printf("a = [%d] \n", p->pa[i]);
	printf("\n");
	return (SUCCESS);
}

void	disp_st( t_p *p)
{
	int i;

	int max = (p->lena > p->lenb) ? p->lena : p->lenb;

	max += 1;
	while (--max >= 0)
	{
		if (p->lenb > 0)
			printf("b = [%d]", p->pb[max]);
		else
			printf("b = []");
		if (p->lena > 0)
			printf("               a = [%d]", p->pa[max]);
		else
			printf("               a = []");
		printf("\n");
	}
}

int		main(int ac, char **av)
{
	t_p *p;

	if (check_error(ac , av) == 1)
		return(err_msg("Error\n"));
	if (ac == 1)
		return (SUCCESS);
	p = malloc(sizeof(t_p));
	if (!p)
		return (ERROR);
	if (fill_pile(ac, av, p) == 1)
	{
		free(p);
		return (err_msg("Error\n"));
	}


	disp_st(p);


	pb(p);

	printf("\n\n");
	disp_st(p);

	free(p);
	return (SUCCESS);
}
