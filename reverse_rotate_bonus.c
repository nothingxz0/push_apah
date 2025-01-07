/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:26:34 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:51:07 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	first = *head;
	last = ft_lstlast_1(first);
	while (first->next)
	{
		new_last = first;
		first = first->next;
	}
	first = *head;
	last->next = first;
	*head = last;
	new_last->next = NULL;
}

void	rra_bonus(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
}

void	rrb_bonus(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(b);
}

void	rrr_bonus(t_list **a, t_list **b)
{
	int	a_rotatable;
	int	b_rotatable;

	a_rotatable = (a && *a && (*a)->next);
	b_rotatable = (b && *b && (*b)->next);
	if (!a_rotatable && !b_rotatable)
		return ;
	if (a_rotatable)
		reverse_rotate(a);
	if (b_rotatable)
		reverse_rotate(b);
}
