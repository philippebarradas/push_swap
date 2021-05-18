/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:34:17 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/16 19:34:36 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*t;

	t = (unsigned char *)s;
	i = -1;
	while (++i < n)
		t[i] = '\0';
}
