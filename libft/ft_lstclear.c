/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:05:49 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/21 12:18:34 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *p_list;

	if (del)
	{
		while (*lst)
		{
			del((*lst)->content);
			p_list = *lst;
			*lst = p_list->next;
			free(p_list);
		}
	}
	*lst = NULL;
}
