# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 10:08:07 by rcosta-c          #+#    #+#              #
#    Updated: 2024/07/04 12:22:21 by rcosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = main.c ft_stacking.c ft_find_error.c ft_stack_utils.c \
	  ft_sort_stack.c ft_sort_three.c ft_median.c ft_rotate.c \
	  ft_ops.c ft_order.c 

OBJECTS = $(SOURCES:.c=.o)

CLR_RMV         := \033[0m
RED                 := \033[1;31m
GREEN           := \033[1;32m
YELLOW          := \033[1;33m
BLUE            := \033[1;34m
CYAN            := \033[1;36m

${NAME}: $(OBJECTS)
		@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
		make bonus -C libft
		cp libft/libft.a .
		${CC} ${CFLAGS} -o ${NAME} ${OBJECTS} libft.a
		@echo "$(GREEN)$(NAME)$(BLUE)✔️ All jobs done!✔️"


all: ${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJECTS)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)OBJECTS ✔️ "

fclean: clean
	make fclean -C libft
	rm -f $(NAME) libft.a
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)bynary ✔️"

re: fclean all

.PHONY: all bonus clean fclean re
