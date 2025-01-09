/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:46:45 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/09 17:35:53 by slasfar          ###   ########.fr       */
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

void	handle_error(t_list **stack_a, t_list **stack_b)
{
	free_list(*stack_a);
	free_list(*stack_b);
	write (2, "Error\n", 6);
	exit(1);
}

void	check_if(t_list **stack_a, t_list **stack_b, char *line, int *flag)
{
	if (!(ft_strcmp(line, "sa\n")))
		sa_bonus(stack_a);
	else if (!(ft_strcmp(line, "sb\n")))
		sb_bonus(stack_b);
	else if (!(ft_strcmp(line, "ss\n")))
		ss_bonus(stack_a, stack_b);
	else if (!(ft_strcmp(line, "pa\n")))
		pa_bonus(stack_a, stack_b);
	else if (!(ft_strcmp(line, "pb\n")))
		pb_bonus(stack_a, stack_b);
	else if (!(ft_strcmp(line, "ra\n")))
		ra_bonus(stack_a);
	else if (!(ft_strcmp(line, "rb\n")))
		rb_bonus(stack_b);
	else if (!(ft_strcmp(line, "rr\n")))
		rr_bonus(stack_a, stack_b);
	else if (!(ft_strcmp(line, "rra\n")))
		rra_bonus(stack_a);
	else if (!(ft_strcmp(line, "rrb\n")))
		rrb_bonus(stack_b);
	else if (!(ft_strcmp(line, "rrr\n")))
		rrr_bonus(stack_a, stack_b);
	else
		*flag = 0;
}

void	do_inst(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		flag;

	flag = 1;
	line = get_next_line(0, flag);
	while (line)
	{
		check_if(stack_a, stack_b, line, &flag);
		free(line);
		line = get_next_line(0, flag);
	}
	if (flag == 0)
		handle_error(stack_a, stack_b);
	if (is_sorted(*stack_a) && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
