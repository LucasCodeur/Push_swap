/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:52:45 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/11 17:39:02 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				top;
	size_t			count;
	size_t			pos;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*pair;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
}					t_data;

typedef struct s_memory
{
	t_bool			is_up;
	t_bool			first_iteration;
	t_stack			*temp_stack;
	t_stack			*temp_node;
	t_stack			*temp_top;
}					t_memory;

// Stack
t_stack				*create_node(int nb);
size_t				count_nodes(t_stack *stack);
void				compute_pos_of_nodes(t_stack **stack);
void				ft_addback_circular(t_stack *new_node, t_stack **stack);
void				free_stack(t_stack **stack);

// Instruction
void				ft_swap(t_stack **head);
void				ft_push(t_stack **node_to_push, t_stack **receiving_stack);
void				ft_rotate(t_stack **stack);
void				ft_reverse_rotate(t_stack **stack);
void				sa(t_stack **stack_a, t_stack **stack_b);
void				sb(t_stack **stack_b, t_stack **stack_a);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, t_stack **stack_b);
void				rb(t_stack **stack_b, t_stack **stack_a);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a, t_stack **stack_b);
void				rrb(t_stack **stack_b, t_stack **stack_a);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				put_max_on_top_b(t_stack **stack_b, t_stack **stack_a);
void				put_min_on_top_a(t_stack **stack_a, t_stack **stack_b);

// Algo
t_stack				*detect_best_count(t_stack **stack);
t_stack				*find_the_biggest(t_stack **stack);
t_stack				*find_the_smallest(t_stack **stack);
void				count_top(t_stack **stack, t_stack *head);
void				compute_count(t_stack **node_to_push,
						t_stack **receiving_stack);
void				count_instruction_a(t_stack **stack_to_push,
						t_stack **receiving_stack);
void				count_instruction_b(t_stack **stack_to_push,
						t_stack **receiving_stack);
t_bool				know_if_the_smallest_nb(t_stack *initial_nb,
						t_stack *stack_to_check);
t_bool				know_if_the_biggest_nb(t_stack *initial_nb,
						t_stack *stack_to_find);
void				sort_3(t_stack **stack_a, t_stack **stack_b);
void				sort_4(t_stack **stack_a, t_stack **stack_b);
void				sort_small(t_stack **stack_a, t_stack **stack_b);
t_bool				sort_in_different_cases(t_stack **stack_a,
						t_stack **stack_b);
t_bool				is_sorted(t_stack **stack_a);
void				push_in_good_place(t_stack **stack_a, t_stack **stack_b);

// Parsing
t_bool				ft_is_digit(int c);
t_bool				ft_isspace(int c);
t_bool				ft_is_plus_or_minus(int c);
t_bool				check_doublon(t_stack **stack);
int					write_error(char *str);
void				check_if_only_space(char *str, t_bool *just_space);
t_bool				parsing(char *str, t_stack **stack);
t_bool				parsing_2(char *str, t_stack **stack);
long				ft_atol(const char *string);
int					ft_atoi_handle_overflow(const char *str, t_bool *error);
void				skip_the_digit(size_t *i, char *str);

// Utils
int					ft_abs(int nb);

// Error
int					write_error(char *str);

#endif
