/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:47:56 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 11:53:35 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
