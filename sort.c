/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:46:45 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/06 13:10:03 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*tmp;

	if (!stack_a)
		return (1);
	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_ranks(t_list *stack_a)
{
	t_list	*head;
	t_list	*compare;

	head = stack_a;
	while (head)
	{
		compare = stack_a;
		head->rank = 1;
		while (compare)
		{
			if (head->content > compare->content)
				head->rank++;
			compare = compare->next;
		}
		head = head->next;
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else
	{
		assign_ranks(*stack_a);
		sort_more(stack_a, stack_b);
	}
}
