/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:05:17 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:50:53 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	init_a(t_list **stack_a, char **stock)
{
	int	j;
	int	flag;
	int	tmp;

	(1) && (j = 0, flag = 1);
	while (stock[j] != NULL)
	{
		tmp = ft_atoi(stock[j], &flag);
		if (flag == 0)
		{
			free_split(stock);
			free_list(*stack_a);
			write (2, "Error\n", 6);
			exit(1);
		}
		if (!ft_lstadd_back(stack_a, ft_lstnew(tmp)))
		{
			free_split(stock);
			free_list(*stack_a);
			write (2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
}
