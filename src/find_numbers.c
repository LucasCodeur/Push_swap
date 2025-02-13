/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:26:33 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:25:40 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_the_biggest(t_stack **stack)
{
	t_stack	*biggest;
	t_stack	*temp;

	temp = (*stack)->next;
	biggest = *stack;
	while (temp != *stack)
	{
		if (biggest->nb < temp->nb)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}

t_stack	*find_the_smallest(t_stack **stack)
{
	t_stack	*smallest;
	t_stack	*temp;

	temp = (*stack)->next;
	smallest = *stack;
	while (temp != *stack)
	{
		if (smallest->nb > temp->nb)
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

t_bool	know_if_the_biggest_nb(t_stack *initial_nb, t_stack *stack_to_check)
{
	t_stack	*temp;
	t_bool	first_iteration;
	t_bool	is_biggest;

	temp = stack_to_check;
	first_iteration = TRUE;
	is_biggest = TRUE;
	while (temp != stack_to_check || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		if (initial_nb->nb < temp->nb)
		{
			is_biggest = FALSE;
			break ;
		}
		temp = temp->next;
	}
	return (is_biggest);
}

t_bool	know_if_the_smallest_nb(t_stack *initial_nb, t_stack *stack_to_check)
{
	t_stack	*temp;
	t_bool	first_iteration;
	t_bool	is_smallest;

	temp = stack_to_check;
	first_iteration = TRUE;
	is_smallest = TRUE;
	while (temp != stack_to_check || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		if (initial_nb->nb > temp->nb)
		{
			is_smallest = FALSE;
			break ;
		}
		temp = temp->next;
	}
	return (is_smallest);
}
