/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:24:45 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/09 16:56:39 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(int a, int b)
{
	return (a * (a >= b) + b * (b > a));
}

void	calculate_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		size_a;
	int		size_b;
	int		target_pos;

	(1) && (head_a = *stack_a, head_b = *stack_b,
	size_a = ft_lstsize(*stack_a), size_b = ft_lstsize(*stack_b));
	while (head_a)
	{
		target_pos = get_pos(*stack_b, head_a->target_node);
		head_a->cost_node = size_a - head_a->pos + 1;
		if (head_a->pos <= (size_a / 2))
			head_a->cost_node = head_a->pos - 1;
		head_a->target_cost = size_b - target_pos + 1;
		if (target_pos <= (size_b / 2))
			head_a->target_cost = target_pos - 1;
		head_a->cost = head_a->cost_node + head_a->target_cost;
		if ((head_a->pos <= (size_a / 2) && target_pos <= (size_b / 2))
			|| (head_a->pos > (size_a / 2) && target_pos > (size_b / 2)))
			head_a->cost = ft_max(head_a->cost_node, head_a->target_cost);
		head_a = head_a->next;
	}
}

static void	push_untill_three_small(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int init_size;
	int	count;

	(1) && (size = ft_lstsize(*stack_a), count = 0, i = 0);
	init_size = size;
	while (i < init_size)
	{
		if ((*stack_a)->rank > size / 2)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		size = ft_lstsize(*stack_a);
		i++;
	}
	while (ft_lstsize(*stack_a) > 3)
		pb(stack_a, stack_b);
}

static void	push_untill_three_large(t_list **stack_a, t_list **stack_b,
	int fpv1, int fpv2)
{
	int	i;
	int	size;
	int	devide_a;
	int	devide_b;

	(1) && (size = ft_lstsize(*stack_a), i = 0, devide_a = 0);
	while (size != 3)
	{
		(1) && (i = 0, devide_b = (ft_lstsize(*stack_a) / fpv1));
		devide_a += (ft_lstsize(*stack_a) / fpv2);
		while (ft_lstsize(*stack_b) < devide_a && i < size && size > 3)
		{
			if (*stack_b && (*stack_b)->rank <= devide_b && (*stack_a)->rank >= devide_a)
				rr(stack_a, stack_b);
			else if (*stack_b && (*stack_b)->rank <= devide_b)
				rb(stack_b);
			if ((*stack_a)->rank <= devide_a)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			size = ft_lstsize(*stack_a);
			i++;
		}
	}
}

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		min_pos;

	if (ft_lstsize(*stack_a) <= 50)
		push_untill_three_small(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 150)
		push_untill_three_large(stack_a, stack_b, 4, 2);
	else
		push_untill_three_large(stack_a, stack_b, 7, 3);
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_pos(stack_a, stack_b);
		find_target_b(stack_a, stack_b);
		calculate_cost(stack_b, stack_a);
		cheapest_up(stack_a, stack_b);
	}
	min = get_min(stack_a);
	min_pos = get_pos(*stack_a, min);
	move_min(stack_a, min_pos, ft_lstsize(*stack_a));
}
