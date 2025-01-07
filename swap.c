/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:37:55 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:45:03 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	int	a_swappable;
	int	b_swappable;

	a_swappable = (a && *a && (*a)->next);
	b_swappable = (b && *b && (*b)->next);
	if (!a_swappable && !b_swappable)
		return ;
	if (a_swappable)
		swap(a);
	if (b_swappable)
		swap(b);
	write(1, "ss\n", 3);
}
