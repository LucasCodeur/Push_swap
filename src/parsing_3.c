/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:35:56 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/11 18:38:22 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_only_space(char *str, t_bool *just_space)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == FALSE)
		{
			*just_space = FALSE;
			break ;
		}
		i++;
	}
}

t_bool	parsing_2(char *str, t_stack **stack)
{
	size_t	i;
	int		nb;
	t_bool	error;

	i = 0;
	error = FALSE;
	while (str[i])
	{
		nb = ft_atoi_handle_overflow(&str[i], &error);
		ft_addback_circular(create_node(nb), stack);
		skip_the_digit(&i, str);
	}
	if (check_doublon(stack) == TRUE || error == TRUE)
	{
		free_stack(stack);
		write_error("Error\n");
		return (FALSE);
	}
	return (TRUE);
}
