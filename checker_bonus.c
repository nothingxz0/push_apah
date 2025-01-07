/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:48:25 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/04 18:50:20 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**stock;
	int		flag;

	flag = 1;
	if (ac < 2)
		exit(1);
	(1) && (i = 1, stack_a = NULL, stack_b = NULL);
	while (i < ac)
	{
		stock = ft_split(av[i++], ' ', &flag);
		if (flag == 0)
		{
			free_split(stock);
			free_list(stack_a);
			write (2, "Error\n", 6);
			exit(1);
		}
		init_a(&stack_a, stock);
		free_split(stock);
	}
	do_inst(&stack_a, &stack_b);
	return (free_list(stack_a), free_list(stack_b), 0);
}
