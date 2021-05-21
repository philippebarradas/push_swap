/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:11:50 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/21 19:12:23 by philippe         ###   ########.fr       */
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

typedef struct s_p
{
	int			*pa;
	int			*pb;

	int			lena;
	int			lenb;

	int			max;
	int			count;

}				t_p;

int	pa_top_is_max(t_p *p);
int	pb_top_is_min(t_p *p);
int	pb_is_trim(t_p *p);
int	pa_is_trim(t_p *p);

int			is_sort(t_p *p);
int			loop(t_p *p);


int			err_msg(char *str);
int			check_error(int ac, char **av, int x, int y);

void		ffree(void *str);
void		free_all(t_p *p);
void		disp_st( t_p *p);

void		sa(t_p *p, int x);
void		sb(t_p *p, int x);
void		ss(t_p *p, int x);
void		pa(t_p *p, int x);
void		pb(t_p *p, int x);

void		ra(t_p *p, int x);
void		rb(t_p *p, int x);
void		rr(t_p *p, int x);
void		rra(t_p *p, int x);
void		rrb(t_p *p, int x);
void		rrr(t_p *p, int x);

void	ft_putstr_fd_count(char *s, int fd, t_p *p);

int short_loop(t_p *p);

#endif
