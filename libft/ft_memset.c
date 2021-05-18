/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:18:30 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/21 17:01:04 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*t;

	t = (unsigned char *)b;
	i = -1;
	while (++i < len)
		t[i] = (unsigned char)c;
	return ((void *)t);
}
