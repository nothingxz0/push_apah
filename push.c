/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:56:55 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 14:13:56 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*first_s;

	first_s = *src;
	*src = (*src)->next;
	first_s->next = *dest;
	*dest = first_s;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
