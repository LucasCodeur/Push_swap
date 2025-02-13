/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:38:26 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:50:36 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*t;
	t_stack	*b;

	t = *stack_a;
	b = (*stack_a)->prev;
	if (t->nb > t->next->nb && t->next->nb > b->nb && t->nb > b->nb)
	{
		ra(stack_a, stack_b);
		sa(stack_a, stack_b);
	}
	else if (t->nb < t->next->nb && t->next->nb > b->nb && t->nb > b->nb)
		rra(stack_a, stack_b);
	else if (t->nb < t->next->nb && t->nb < b->nb && t->next->nb > b->nb)
	{
		sa(stack_a, stack_b);
		ra(stack_a, stack_b);
	}
	else if (t->nb > t->next->nb && t->nb > b->nb)
	{
		rra(stack_a, stack_b);
		rra(stack_a, stack_b);
	}
	else if (t->nb > t->next->nb && t->next->nb < b->nb)
		sa(stack_a, stack_b);
	return ;
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	put_min_on_top_a(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a, stack_b);
	pa(stack_b, stack_a);
	return ;
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_nodes;

	nb_nodes = count_nodes(*stack_a);
	if (nb_nodes == 3)
		sort_3(stack_a, stack_b);
	else
		sort_4(stack_a, stack_b);
	return ;
}

t_bool	sort_in_different_cases(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a) == TRUE)
		return (TRUE);
	if (count_nodes(*stack_a) == 1)
		return (TRUE);
	if (count_nodes(*stack_a) == 2)
	{
		if ((*stack_a)->nb > (*stack_a)->next->nb)
		{
			sa(stack_a, stack_b);
			return (TRUE);
		}
		return (TRUE);
	}
	if (count_nodes(*stack_a) == 3)
	{
		sort_3(stack_a, stack_b);
		return (TRUE);
	}
	if (count_nodes(*stack_a) == 4)
	{
		sort_4(stack_a, stack_b);
		return (TRUE);
	}
	return (FALSE);
}
