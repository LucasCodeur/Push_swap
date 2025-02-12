/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:29:19 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/11 17:47:59 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_if_input_is_false(char *str)
{
	while (*str != '\0')
	{
		while (ft_isspace(*str) == TRUE)
			str++;
		if (ft_is_plus_or_minus(*str) == TRUE
			&& ft_isdigit(*(str + 1)) == TRUE)
			str++;
		while (ft_isdigit(*str) == TRUE)
			str++;
		if (*str != '\0' && ft_isspace(*str) == FALSE)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	check_doublon(t_stack **stack)
{
	t_bool	first_iteration;
	t_stack	*node_to_check;
	t_stack	*next_node;

	if (*stack == NULL || count_nodes(*stack) == 1)
		return (FALSE);
	node_to_check = *stack;
	next_node = (*stack)->next;
	first_iteration = TRUE;
	while (node_to_check != *stack || first_iteration == TRUE)
	{
		first_iteration = FALSE;
		while (next_node != node_to_check)
		{
			if (node_to_check->nb == next_node->nb)
				return (TRUE);
			next_node = next_node->next;
		}
		node_to_check = node_to_check->next;
		next_node = node_to_check->next;
	}
	return (FALSE);
}

void	skip_the_digit(size_t *i, char *str)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	while (str[*i] && str[*i] != ' ')
		(*i)++;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}

t_bool	parsing(char *str, t_stack **stack)
{
	t_bool	just_space;

	just_space = TRUE;
	if (str == NULL || str[0] == '\0')
	{
		free_stack(stack);
		write_error("Error\n");
		return (FALSE);
	}
	check_if_only_space(str, &just_space);
	if (check_if_input_is_false(str) == TRUE || just_space == TRUE)
	{
		free_stack(stack);
		write_error("Error\n");
		return (FALSE);
	}
	return (TRUE);
}
