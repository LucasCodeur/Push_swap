/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:02:33 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:47:50 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*detect_best_count(t_stack **stack)
{
	t_stack	*best_count;
	t_stack	*temp;

	best_count = *stack;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		if (best_count->count > temp->count)
			best_count = temp;
		temp = temp->next;
	}
	return (best_count);
}

void	push_in_good_place(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_count;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b, stack_a);
	while (count_nodes(*stack_a) > 4)
	{
		count_instruction_a(stack_a, stack_b);
		best_count = detect_best_count(stack_a);
		reach_top_a(stack_a, stack_b, &best_count);
		pb(stack_a, stack_b);
	}
	sort_small(stack_a, stack_b);
	put_max_on_top_b(stack_b, stack_a);
	while (count_nodes(*stack_b) > 0)
	{
		count_instruction_b(stack_b, stack_a);
		best_count = detect_best_count(stack_b);
		reach_top_b(stack_b, stack_a, &best_count);
		pa(stack_b, stack_a);
	}
	count_top(stack_a, *stack_a);
	put_min_on_top_a(stack_a, stack_b);
}
