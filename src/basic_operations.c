/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:26:27 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 11:43:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **node_to_push, t_stack **receiving_stack)
{
	t_stack	*head;

	head = *node_to_push;
	if (head->next == head)
		*node_to_push = NULL;
	else
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		*node_to_push = head->next;
	}
	if (!*receiving_stack)
	{
		*receiving_stack = head;
		(*receiving_stack)->next = *receiving_stack;
		(*receiving_stack)->prev = *receiving_stack;
	}
	else
	{
		(*receiving_stack)->prev->next = head;
		head->prev = (*receiving_stack)->prev;
		head->next = *receiving_stack;
		(*receiving_stack)->prev = head;
		*receiving_stack = head;
	}
}

void	ft_swap(t_stack **stack)
{
	t_stack	*second_node;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	second_node = (*stack)->next;
	(*stack)->next = second_node->next;
	second_node->next->prev = *stack;
	second_node->prev = (*stack)->prev;
	(*stack)->prev->next = second_node;
	second_node->next = *stack;
	(*stack)->prev = second_node;
	*stack = second_node;
}

void	ft_rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ft_reverse_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}
