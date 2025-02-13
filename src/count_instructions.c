/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:42 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:44:16 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_instruction_a(t_stack **stack_to_push, t_stack **receiving_stack)
{
	t_stack	*temp;
	t_bool	first_iteration;

	temp = *stack_to_push;
	first_iteration = TRUE;
	while (temp != *stack_to_push || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		temp->pair = find_the_correspondant_a(temp, *receiving_stack);
		temp = temp->next;
	}
	first_iteration = TRUE;
	count_top(stack_to_push, *stack_to_push);
	count_top(receiving_stack, *receiving_stack);
	while (temp != *stack_to_push || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		compute_count(&temp, &temp->pair);
		temp = temp->next;
	}
}

void	count_instruction_b(t_stack **stack_to_push, t_stack **receiving_stack)
{
	t_stack	*temp;
	t_bool	first_iteration;

	temp = *stack_to_push;
	first_iteration = TRUE;
	while (temp != *stack_to_push || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		temp->pair = find_the_correspondant_b(temp, *receiving_stack);
		temp = temp->next;
	}
	first_iteration = TRUE;
	count_top(stack_to_push, *stack_to_push);
	count_top(receiving_stack, *receiving_stack);
	while (temp != *stack_to_push || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		compute_count(&temp, &temp->pair);
		temp = temp->next;
	}
}
