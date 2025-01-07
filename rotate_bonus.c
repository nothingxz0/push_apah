/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:12:33 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:51:15 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	first = *head;
	second = first->next;
	last = ft_lstlast_1(first);
	last->next = first;
	first->next = NULL;
	*head = second;
}

void	ra_bonus(t_list **head)
{
	if (!head || !*head || !(*head)->next)
		return ;
	rotate(head);
}

void	rb_bonus(t_list **head)
{
	if (!head || !*head || !(*head)->next)
		return ;
	rotate(head);
}

void	rr_bonus(t_list **stack_a, t_list **stack_b)
{
	int	a_rotatable;
	int	b_rotatable;

	a_rotatable = (stack_a && *stack_a && (*stack_a)->next);
	b_rotatable = (stack_b && *stack_b && (*stack_b)->next);
	if (!a_rotatable && !b_rotatable)
		return ;
	if (a_rotatable)
		rotate(stack_a);
	if (b_rotatable)
		rotate(stack_b);
}
