/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:06:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/01/26 19:20:09 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_b || !stack_a || !*stack_b)
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	if (ft_printf("rrr\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	put_max_on_top_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*max;
	t_stack	*temp;

	max = *stack_b;
	temp = (*stack_b)->next;
	if (*stack_b == (*stack_b)->next)
		return ;
	while (temp != *stack_b)
	{
		if (temp->nb > max->nb)
			max = temp;
		temp = temp->next;
	}
	while (max->top < 0)
	{
		rrb(stack_b, stack_a);
		max->top++;
	}
	while (max->top > 0)
	{
		rb(stack_b, stack_a);
		max->top--;
	}
}

void	put_max_on_top_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	t_stack	*temp;

	max = *stack_a;
	temp = (*stack_a)->next;
	while (temp != *stack_a)
	{
		if (temp->nb > max->nb)
			max = temp;
		temp = temp->next;
	}
	count_top(stack_a, *stack_a);
	while (max->top < 0)
	{
		rra(stack_a, stack_b);
		max->top++;
	}
	while (max->top > 0)
	{
		ra(stack_a, stack_b);
		max->top--;
	}
}

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
