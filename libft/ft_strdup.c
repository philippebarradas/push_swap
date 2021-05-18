/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:25:03 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/17 14:25:36 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		len;
	char	*str;
	int		i;

	i = -1;
	len = 0;
	while (s1[len])
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
