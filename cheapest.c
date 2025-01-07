/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:55:05 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 11:22:04 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_cheapest(t_list **stack_a, t_list **cheapest)
{
	t_list	*head_a;

	head_a = *stack_a;
	*cheapest = head_a;
	while (head_a)
	{
		if (head_a->cost < (*cheapest)->cost)
			*cheapest = head_a;
		head_a = head_a->next;
	}
}

void	cheapest_up(t_list **stack_a, t_list **stack_b)
{	
	t_list	*cheapest;
	int		size_a;
	int		size_b;
	int		target_pos;

	(1) && (size_a = ft_lstsize(*stack_a), size_b = ft_lstsize(*stack_b),
	cheapest = NULL);
	find_cheapest(stack_b, &cheapest);
	target_pos = get_pos(*stack_a, cheapest->target_node);
	if (target_pos <= (size_a / 2) && cheapest->pos <= (size_b / 2))
		rotate_both(stack_a, stack_b, &cheapest->target_cost,
			&cheapest->cost_node);
	else if (target_pos > (size_a / 2) && cheapest->pos > (size_b / 2))
		reverse_rotate_both(stack_a, stack_b, &cheapest->target_cost,
			&cheapest->cost_node);
	move_to_top_b(stack_b, cheapest->pos, size_b, &cheapest->cost_node);
	move_to_top(stack_a, target_pos, size_a, &cheapest->target_cost);
	pa(stack_a, stack_b);
}
