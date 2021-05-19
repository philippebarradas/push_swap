/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:20:49 by phbarrad          #+#    #+#             */
/*   Updated: 2021/05/19 14:29:59 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &(s[i]), 1);
}

int	ft_putstr_fd_ret(char *s, int fd, int ret)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &(s[i]), 1);
	return (ret);
}
