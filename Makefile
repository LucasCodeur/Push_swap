# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 16:42:49 by lud-adam          #+#    #+#              #
#    Updated: 2025/01/20 20:05:52 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := src/
OBJ_DIR := obj/
INC_DIR := include/
HEADERS := $(INC_DIR)push_swap.h
LIBFT_DIR := libft/
FT_PRINTF_DIR := $(LIBFT_DIR)ft_printf
MAKE := $(MAKE) -j --no-print-directory

SRC = \
	$(SRC_DIR)basic_operations.c    $(SRC_DIR)create_stack.c        $(SRC_DIR)functions_utils.c         $(SRC_DIR)operations_stack_a.c  $(SRC_DIR)turk_algo.c \
	$(SRC_DIR)check_input.c         $(SRC_DIR)main.c                $(SRC_DIR)operations_stack_b.c  $(SRC_DIR)utils_to_compute_count.c \
	$(SRC_DIR)compute_count.c       $(SRC_DIR)find_correspondant.c  $(SRC_DIR)operations_both_stacks.c  $(SRC_DIR)parsing_utils.c \
	$(SRC_DIR)count_instructions.c  $(SRC_DIR)find_numbers.c        $(SRC_DIR)operations_stack_a_2.c    $(SRC_DIR)sort.c $(SRC_DIR)tree_operations.c

OBJ := $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
NAME := push_swap

LIBFT := $(LIBFT_DIR)libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
INC := -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME) push_swap

re: fclean all

FORCE: 

.PHONY: all clean fclean re 

