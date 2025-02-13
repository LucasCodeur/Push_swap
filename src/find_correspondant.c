/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_correspondant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:04:07 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:44:19 by lud-adam         ###   ########.fr       */
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
