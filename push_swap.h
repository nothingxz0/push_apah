/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slasfar <slasfar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:41:41 by slasfar           #+#    #+#             */
/*   Updated: 2025/01/06 23:33:40 by slasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line.h"

/* Structure */
typedef struct s_list
{
	int				content;
	int				pos;
	int				target_node;
	int				cost;
	int				cost_node;
	int				target_cost;
	int				rank;
	struct s_list	*next;
}	t_list;

/* List Operations */
void	do_inst(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast_1(t_list *lst);
t_list	*ft_lstlast_2(t_list *lst, t_list *new, int *flag);
int		ft_lstsize(t_list *lst);
int		ft_lstadd_back(t_list **lst, t_list *new);
void	free_list(t_list *head);

/* Stack Operations */
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **head);
void	rb(t_list **head);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

/* Stack Bonus Operations */
void	sa_bonus(t_list **a);
void	sb_bonus(t_list **b);
void	ss_bonus(t_list **a, t_list **b);
void	pa_bonus(t_list **stack_a, t_list **stack_b);
void	pb_bonus(t_list **stack_a, t_list **stack_b);
void	ra_bonus(t_list **head);
void	rb_bonus(t_list **head);
void	rr_bonus(t_list **stack_a, t_list **stack_b);
void	rra_bonus(t_list **a);
void	rrb_bonus(t_list **b);
void	rrr_bonus(t_list **a, t_list **b);

/* Sorting Functions */
void	sort(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	find_target_b(t_list **stack_a, t_list **stack_b);
void	sort_more(t_list **stack_a, t_list **stack_b);
void	cheapest_up(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack_a);
void	sort_two(t_list **stack);

/* Moving Functions */
void	move_min(t_list **stack, int pos, int size);
void	move_to_top(t_list **stack, int pos, int size, int *cost);
void	move_to_top_b(t_list **stack, int pos, int size, int *cost);
void	rotate_both(t_list **stack_a, t_list **stack_b,
			int *cost_a, int *cost_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b,
			int *cost_a, int *cost_b);

/* Utility Functions */
void	assign_pos(t_list **stack_a, t_list **stack_b);
void	assign_ranks(t_list *stack_a);
int		get_pos(t_list *stack, int content);
void	init_a(t_list **stack_a, char **stock);
void	free_split(char **split);
int		ft_atoi(const char *nptr, int *flag);
char	**ft_split(char const *s, char c, int *flag);
int		get_min(t_list **stack);
int		ft_strcmp(char *s1, char *s2);

#endif