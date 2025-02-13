/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:47:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:48:10 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reach_top_a(t_stack **stack_a, t_stack **stack_b, t_stack **best_count)
{
	while ((*best_count)->count > 0)
	{
		count_top(stack_a, *stack_a);
		count_top(stack_b, *stack_b);
		if (((*best_count)->top > 0 && (*best_count)->pair->top > 0))
			rr(stack_a, stack_b);
		else if (((*best_count)->top < 0 && (*best_count)->pair->top < 0))
			rrr(stack_a, stack_b);
		else if ((*best_count)->top > 0)
			ra(stack_a, stack_b);
		else if ((*best_count)->top < 0)
			rra(stack_a, stack_b);
		else if ((*best_count)->pair->top > 0)
			rb(stack_b, stack_a);
		else if ((*best_count)->pair->top < 0)
			rrb(stack_b, stack_a);
		(*best_count)->count--;
	}
}

void	reach_top_b(t_stack **stack_a, t_stack **stack_b, t_stack **best_count)
{
	while ((*best_count)->count > 0)
	{
		count_top(stack_a, *stack_a);
		count_top(stack_b, *stack_b);
		if (((*best_count)->top > 0 && (*best_count)->pair->top > 0))
			rr(stack_a, stack_b);
		else if (((*best_count)->top < 0 && (*best_count)->pair->top < 0))
			rrr(stack_a, stack_b);
		else if ((*best_count)->top > 0)
			rb(stack_a, stack_b);
		else if ((*best_count)->top < 0)
			rrb(stack_a, stack_b);
		else if ((*best_count)->pair->top > 0)
			ra(stack_b, stack_a);
		else if ((*best_count)->pair->top < 0)
			rra(stack_b, stack_a);
		(*best_count)->count--;
	}
}
