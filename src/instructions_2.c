/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:35:09 by lud-adam          #+#    #+#             */
/*   Updated: 2025/01/31 18:01:02 by lud-adam         ###   ########.fr       */
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

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (ft_printf("ss\n") == -1)
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
