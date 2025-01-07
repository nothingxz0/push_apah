/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:48:25 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/06 23:32:43 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_malloc(t_list **stack_a)
{
	free_list(*stack_a);
	write (2, "Error\n", 6);
	exit(1);
}

static void	my_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**stock;
	int		flag;

	if (ac < 2)
		exit(1);
	(1) && (flag = 1, i = 1, stack_a = NULL, stack_b = NULL);
	while (i < ac)
	{
		stock = ft_split(av[i++], ' ', &flag);
		if (!stock)
			handle_malloc(&stack_a);
		if (flag == 0)
		{
			free_split(stock);
			free_list(stack_a);
			my_error();
		}
		init_a(&stack_a, stock);
		free_split(stock);
	}
	sort(&stack_a, &stack_b);
	return (free_list(stack_a), free_list(stack_b), 0);
}
