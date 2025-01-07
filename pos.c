/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:51:46 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 12:50:16 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list **stack)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->content;
	while (head)
	{
		if (head->content < min)
			min = head->content;
		head = head->next;
	}
	return (min);
}

int	get_pos(t_list *stack, int content)
{
	int	pos;

	pos = 1;
	while (stack && stack->content != content)
	{
		pos++;
		stack = stack->next;
	}
	stack->pos = pos;
	return (pos);
}

void	assign_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	(1) && (head_a = *stack_a, head_b = *stack_b);
	while (head_a)
	{
		get_pos((*stack_a), head_a->content);
		head_a = head_a->next;
	}
	while (head_b)
	{
		get_pos((*stack_b), head_b->content);
		head_b = head_b->next;
	}
}
