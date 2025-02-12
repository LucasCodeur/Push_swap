/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:32:07 by lud-adam          #+#    #+#             */
/*   Updated: 2025/01/31 18:07:42 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	if (new_node != NULL)
	{
		new_node->nb = nb;
		new_node->pos = 0;
		new_node->top = 0;
		new_node->count = 0;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	return (new_node);
}

void	ft_addback_circular(t_stack *new_node, t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
		return ;
	}
	else
	{
		head->prev->next = new_node;
		new_node->prev = head->prev;
		head->prev = new_node;
		new_node->next = head;
		return ;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	tail = (*stack)->prev;
	while (tail != *stack)
	{
		temp = tail->prev;
		free(tail);
		tail = temp;
	}
	free(tail);
}
