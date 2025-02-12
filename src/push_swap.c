/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:31:09 by lud-adam          #+#    #+#             */
/*   Updated: 2025/01/27 15:13:40 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	j;

	if (argc < 2)
		return (1);
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (++j < (size_t)argc && argv[j])
	{
		if (parsing(argv[j], &stack_a) == FALSE)
			return (1);
		if (parsing_2(argv[j], &stack_a) == FALSE)
			return (1);
	}
	if (sort_in_different_cases(&stack_a, &stack_b) == FALSE)
		push_in_good_place(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
