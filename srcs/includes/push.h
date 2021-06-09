/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:11:50 by phbarrad          #+#    #+#             */
/*   Updated: 2021/06/09 14:25:57 by phbarrad         ###   ########.fr       */
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

	int			val_med_a;
	int			val_med_b;
	int			midd_a;

	int			init_lena;

	int			init_med;
	int			max;
	int			max_b;
	int			maxe;
	int			min;
	int			count;

	int			med;
	int			div;
}				t_p;


void	fillpb_first_med(t_p *p, float av, int len);
void	min_pb_top(t_p *p);
void	oth(t_p *p);
void	fillpa_sec_med(t_p *p, float av, int len);
void	find_min_in_b(t_p *p);

//t3
int		next_val_med_pa(t_p *p);
int		pp_g_med(int *pill, int len, int val_med);
int		pp_d_med(int *pill, int len, int val_med);
int		next_min(t_p *p);
void	find_max_b(t_p *p);

//tool
int		next_min(t_p *p);

int	pp_g_egg(int *pill, int len, int val_med);
int	pp_d_egg(int *pill, int len, int val_med);
int	pp_g_val(int *pill, int len, int val_med);
int	pp_d_val(int *pill, int len, int val_med);

int	next_val_med_pb(t_p *p, int val_med);
int	pp_g(int *pill, int len, int val_med);
int	pp_d(int *pill, int len, int val_med);


int	is_in_pill(int *pil, int nbr, int len);

int		pa_opti_fill(t_p *p);
int		pb_opti_fill(t_p *p);

int find_val_med(t_p *p, int div);
int	pa_top_is_max(t_p *p);
int	pb_top_is_min(t_p *p);
int	pb_is_trim(t_p *p);
int	pa_is_trim(t_p *p);

int	min_is_in_pa(t_p *p, int min);
int	no_val_med_in_a(t_p *p, int val_med);
int	no_val_med_in_b(t_p *p, int val_med);

int find_val_med_in_b(t_p *p, int div);

int			is_sort(t_p *p);
int			loop(t_p *p);
int			long_loop(t_p *p);



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


#endif
