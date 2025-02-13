/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:45:02 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 11:54:37 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	ft_swap(stack_a);
	if (ft_printf("sa\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_b || !*stack_b)
		return ;
	ft_push(stack_b, stack_a);
	if (ft_printf("pa\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	ra(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	ft_rotate(stack_a);
	if (ft_printf("ra\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	rra(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	ft_reverse_rotate(stack_a);
	if (ft_printf("rra\n") == -1)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
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
