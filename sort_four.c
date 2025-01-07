/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:21:39 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 20:12:07 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		pos;
	int		size;
	int		min;

	(1) && (min = get_min(stack_a), head_a = *stack_a);
	(pb(stack_a, stack_b), sort_three(stack_a));
	find_target_b(stack_a, stack_b);
	head_b = *stack_b;
	size = ft_lstsize(*stack_a);
	pos = get_pos(*stack_a, (*stack_b)->target_node);
	move_min(stack_a, pos, size);
	pa(stack_a, stack_b);
	size = ft_lstsize(*stack_a);
	head_a = *stack_a;
	pos = get_pos(*stack_a, min);
	move_min(stack_a, pos, size);
}
