/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:44:57 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:50:32 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*previous;
	int		flag;

	flag = 1;
	if (*lst)
	{
		previous = ft_lstlast_2(*lst, new, &flag);
		previous->next = new;
		new->next = NULL;
	}
	else
		*lst = new;
	if (flag == 0)
		return (0);
	return (1);
}
