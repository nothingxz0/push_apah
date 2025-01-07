/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:38:59 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 21:16:09 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	tp;
	int	md;
	int	bt;

	(1) && (tp = (*stack_a)->content,
	md = (*stack_a)->next->content, bt = (*stack_a)->next->next->content);
	if ((tp > md && md < bt) && tp < bt)
		sa(stack_a);
	else if (tp > md && md > bt)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (tp > md && md < bt)
		ra(stack_a);
	else if ((tp < md && md > bt) && bt > tp)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((tp < md && md > bt) && bt < tp)
		rra(stack_a);
}
