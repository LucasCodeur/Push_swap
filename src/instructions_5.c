/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:02:33 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/11 16:28:55 by lud-adam         ###   ########.fr       */
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

t_bool	is_sorted(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_a;
	tail = (*stack_a)->prev;
	while (temp != tail)
	{
		if (temp->nb > temp->next->nb)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

t_bool	sort_in_different_cases(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a) == TRUE)
		return (TRUE);
	if (count_nodes(*stack_a) == 1)
		return (TRUE);
	if (count_nodes(*stack_a) == 2)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
		{
			sa(stack_a, stack_b);
			return (TRUE);
		}
		return (TRUE);
	}
	if (count_nodes(*stack_a) == 3)
	{
		sort_3(stack_a, stack_b);
		return (TRUE);
	}
	if (count_nodes(*stack_a) == 4)
	{
		sort_4(stack_a, stack_b);
		return (TRUE);
	}
	return (FALSE);
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
