/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:17:22 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 14:14:32 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min(t_list **stack, int pos, int size)
{
	if (pos <= (size / 2))
	{
		pos--;
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = size - pos + 1;
		while (pos--)
			rra(stack);
	}
}

void	move_to_top(t_list **stack, int pos, int size, int *cost)
{
	if (pos <= (size / 2))
	{
		while ((*cost)--)
			ra(stack);
	}
	else
	{
		while ((*cost)--)
			rra(stack);
	}
}

void	move_to_top_b(t_list **stack, int pos, int size, int *cost)
{
	if (pos <= (size / 2))
	{
		while ((*cost)--)
			rb(stack);
	}
	else
	{
		while ((*cost)--)
			rrb(stack);
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b,
	int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}
