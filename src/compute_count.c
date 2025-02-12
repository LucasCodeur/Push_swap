/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:56:25 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/10 14:12:46 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_full_positive(t_stack **node_to_push, t_stack **receiving_stack)
{
	if ((*node_to_push)->top > 0 && (*receiving_stack)->top > 0)
	{
		if ((*node_to_push)->top > (*receiving_stack)->top)
			(*node_to_push)->count = (*node_to_push)->top;
		else
			(*node_to_push)->count = (*receiving_stack)->top;
	}
	else if ((*node_to_push)->top == 0 && (*receiving_stack)->top > 0)
		(*node_to_push)->count = (*receiving_stack)->top;
	else if ((*receiving_stack)->top == 0 && (*node_to_push)->top > 0)
		(*node_to_push)->count = (*node_to_push)->top;
}

static void	top_full_negative(t_stack **node_to_push, t_stack **receiving_stack)
{
	if ((*node_to_push)->top < 0 && (*receiving_stack)->top < 0)
	{
		if ((*node_to_push)->top < (*receiving_stack)->top)
			(*node_to_push)->count = ft_abs((*node_to_push)->top);
		else
			(*node_to_push)->count = ft_abs((*receiving_stack)->top);
	}
	else if ((*node_to_push)->top == 0 && (*receiving_stack)->top < 0)
		(*node_to_push)->count = ft_abs((*receiving_stack)->top);
	else if ((*receiving_stack)->top == 0 && (*node_to_push)->top < 0)
		(*node_to_push)->count = ft_abs((*node_to_push)->top);
}

static void	top_pos_top_neg(t_stack **node_to_push, t_stack **receiving_stack)
{
	(*node_to_push)->count = (*node_to_push)->top \
		+ ft_abs((*receiving_stack)->top);
}

static void	top_neg_top_pos(t_stack **node_to_push, t_stack **receiving_stack)
{
	(*node_to_push)->count = (ft_abs((*node_to_push)->top)) \
		+ (*receiving_stack)->top;
}

void	compute_count(t_stack **node_to_push, t_stack **receiving_stack)
{
	if ((*node_to_push)->top >= 0 && (*receiving_stack)->top >= 0)
		top_full_positive(node_to_push, receiving_stack);
	else if ((*node_to_push)->top <= 0 && (*receiving_stack)->top <= 0)
		top_full_negative(node_to_push, receiving_stack);
	else if ((*node_to_push)->top > 0 && (*receiving_stack)->top < 0)
		top_pos_top_neg(node_to_push, receiving_stack);
	else if ((*node_to_push)->top < 0 && (*receiving_stack)->top > 0)
		top_neg_top_pos(node_to_push, receiving_stack);
}
