/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_instruction_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:00:42 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/05 19:28:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_the_correspondant_a(t_stack *initial_nb, t_stack *stack_to_find)
{
	t_bool	first_iteration;
	t_stack	*find;
	t_stack	*temp;
	long	nb;

	first_iteration = TRUE;
	temp = stack_to_find;
	nb = LONG_MIN;
	if (know_if_the_biggest_nb(initial_nb, stack_to_find) == TRUE
		|| know_if_the_smallest_nb(initial_nb, stack_to_find) == TRUE)
	{
		find = find_the_biggest(&stack_to_find);
		return (find);
	}
	while (temp != stack_to_find || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		if (temp->nb >= nb && temp->nb < initial_nb->nb)
		{
			nb = temp->nb;
			find = temp;
		}
		temp = temp->next;
	}
	return (find);
}

t_stack	*find_the_correspondant_b(t_stack *initial_nb, t_stack *stack_to_find)
{
	t_stack	*find;
	t_stack	*temp;
	long	nb;
	t_bool	first_iteration;

	first_iteration = TRUE;
	temp = stack_to_find;
	nb = LONG_MAX;
	if (know_if_the_biggest_nb(initial_nb, stack_to_find) == TRUE
		|| know_if_the_smallest_nb(initial_nb, stack_to_find) == TRUE)
	{
		find = find_the_smallest(&stack_to_find);
		return (find);
	}
	while (temp != stack_to_find || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		if (temp->nb >= initial_nb->nb && temp->nb < nb)
		{
			nb = temp->nb;
			find = temp;
		}
		temp = temp->next;
	}
	return (find);
}

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
