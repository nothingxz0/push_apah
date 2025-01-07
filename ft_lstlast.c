/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:35:00 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:50:36 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast_1(t_list *lst)
{
	t_list	*pr;

	pr = NULL;
	while (lst)
	{
		pr = lst;
		lst = lst->next;
	}
	return (pr);
}

// handling dup here XD
t_list	*ft_lstlast_2(t_list *lst, t_list *new, int *flag)
{
	t_list	*pr;

	pr = NULL;
	while (lst)
	{
		pr = lst;
		if (pr->content == new->content)
			*flag = 0;
		lst = lst->next;
	}
	return (pr);
}
