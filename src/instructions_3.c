/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:55:48 by lud-adam          #+#    #+#             */
/*   Updated: 2025/01/31 18:01:27 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (ft_printf("rr\n") == -1)
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
