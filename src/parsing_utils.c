/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:35:47 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:19:51 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_handle_overflow(const char *str, t_bool *error)
{
	int		sign;
	int		i;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) == TRUE)
		i++;
	if (ft_is_plus_or_minus(str[i]) == TRUE)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == TRUE && str[i] != '\0')
	{
		if (compute_size_long(result) > 10)
			*error = TRUE;
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && result < INT_MIN))
		*error = TRUE;
	return ((int)result * sign);
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
