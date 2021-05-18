/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:19:58 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/24 16:41:05 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_putfd(char c, int fd)
{
	write(fd, &c, 1);
}

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		ft_putfd('-', fd);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putfd((nbr % 10) + '0', fd);
}
