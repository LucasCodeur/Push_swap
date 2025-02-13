/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:35:09 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:00:06 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_b || !*stack_b)
		return ;
	ft_swap(stack_b);
	if (ft_printf("sb\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	ft_push(stack_a, stack_b);
	if (ft_printf("pb\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	rrb(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_b || !*stack_b)
		return ;
	ft_reverse_rotate(stack_b);
	if (ft_printf("rrb\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	rb(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_b || !*stack_b)
		return ;
	ft_rotate(stack_b);
	if (ft_printf("rb\n") == -1)
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
