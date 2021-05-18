/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:11:50 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/18 16:29:34 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SUCCESS 0
# define ERROR 1

typedef struct	s_p
{
	int			*pa;
	int			*pb;

	int			lena;
	int			lenb;

}				t_p;

int			err_msg(char *str);
int			check_error(int ac, char **av);
void		sa(t_p *p);
void		sb(t_p *p);
void		ss(t_p *p);
void		pa(t_p *p);
void		pb(t_p *p);
void		ra(t_p *p);
void		rb(t_p *p);
void		rr(t_p *p);
void		rra(t_p *p);
void		rrb(t_p *p);
void		rrr(t_p *p);

#endif

