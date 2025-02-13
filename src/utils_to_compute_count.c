/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_compute_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:52 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 13:35:09 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_memory	*memory_init(t_stack **stack)
{
	t_memory	*memory;

	compute_pos_of_nodes(stack);
	memory = malloc(sizeof(t_memory));
	if (!memory)
		return (NULL);
	memory->is_up = FALSE;
	memory->first_iteration = TRUE;
	memory->temp_stack = *stack;
	memory->temp_node = NULL;
	memory->temp_top = NULL;
	return (memory);
}

size_t	count_nodes(t_stack *stack)
{
	t_stack	*tail;
	size_t	count;

	if (!stack)
		return (0);
	if (stack == stack->next)
		return (1);
	tail = stack->prev;
	count = 1;
	while (stack != tail)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	compute_pos_of_nodes(t_stack **stack)
{
	size_t	pos;
	t_stack	*temp;
	t_bool	first_iteration;

	if (!stack || !*stack)
		return ;
	pos = 1;
	temp = *stack;
	temp->top = 0;
	first_iteration = TRUE;
	while (temp != *stack || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		temp->pos = pos;
		temp->top = 0;
		pos++;
		temp = temp->next;
	}
}

static t_bool	choose_sense_of_loop(t_stack *stack, t_stack *head)
{
	size_t		length_total;
	size_t		half_length;
	t_bool		is_up;

	is_up = FALSE;
	if (!stack || !head)
		return (FALSE);
	length_total = count_nodes(head);
	half_length = (length_total / 2) + 1;
	if (stack->pos <= half_length)
		is_up = TRUE;
	else if (stack->pos > half_length)
		is_up = FALSE;
	return (is_up);
}

void	count_top(t_stack **stack, t_stack *head)
{
	t_memory	*memory;

	memory = memory_init(stack);
	while (memory->temp_stack != head || memory->first_iteration == TRUE)
	{
		memory->first_iteration = FALSE;
		memory->temp_node = memory->temp_stack;
		memory->temp_top = memory->temp_node;
		memory->is_up = choose_sense_of_loop(memory->temp_node, head);
		while (memory->temp_node != head)
		{
			if (memory->is_up == TRUE)
			{
				memory->temp_top->top++;
				memory->temp_node = memory->temp_node->prev;
			}
			else if (memory->is_up == FALSE)
			{
				memory->temp_top->top--;
				memory->temp_node = memory->temp_node->next;
			}
		}
		memory->temp_stack = memory->temp_stack->next;
	}
	free(memory);
}
