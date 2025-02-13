/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:55:18 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:50:33 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_on_top_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	t_stack	*temp;

	min = *stack_a;
	temp = (*stack_a)->next;
	while (temp != *stack_a)
	{
		if (temp->nb < min->nb)
			min = temp;
		temp = temp->next;
	}
	count_top(stack_a, *stack_a);
	while (min->top < 0)
	{
		rra(stack_a, stack_b);
		min->top++;
	}
	while (min->top > 0)
	{
		ra(stack_a, stack_b);
		min->top--;
	}
}
