/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:30:29 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 11:24:29 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_min_2(t_list **stack_a, t_list *head_b)
{
	t_list	*head_a;
	int		target;

	head_a = *stack_a;
	target = head_a->content;
	while (head_a)
	{
		if (head_a->content < target)
			target = head_a->content;
		head_a = head_a->next;
	}
	head_b->target_node = target;
}

void	find_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		target;
	int		found_target;

	(1) && (head_a = *stack_a, head_b = *stack_b, target = head_a->content);
	while (head_b)
	{
		(1) && (head_a = *stack_a, target = INT_MAX, found_target = 0);
		while (head_a)
		{
			if (head_a->content > head_b->content
				&& head_a->content < target)
			{
				target = head_a->content;
				head_b->target_node = head_a->content;
				found_target = 1;
			}
			head_a = head_a->next;
		}
		if (!found_target)
			get_min_2(stack_a, head_b);
		head_b = head_b->next;
	}
}
