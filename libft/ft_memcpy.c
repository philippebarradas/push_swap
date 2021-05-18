/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:12:37 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/17 14:12:55 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*td;
	unsigned char	*ts;

	td = (unsigned char *)dest;
	ts = (unsigned char *)src;
	i = -1;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (++i < n)
		td[i] = ts[i];
	return (dest);
}
