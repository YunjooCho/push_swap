# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:32:34 by yunjcho           #+#    #+#              #
#    Updated: 2023/02/14 22:11:44 by yunjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SRCS = push_swap.c ps_utils.c ps_parse.c ps_index.c ps_init1.c ps_init2.c \
		ps_sort1.c ps_sort2.c ps_sort3.c ps_calculate.c \
		ps_deque.c ps_deque_utils.c \
		ps_command1.c ps_command2.c
SRCS_BONUS = push_swap_bonus.c ps_utils.c ps_parse.c ps_index.c ps_init1.c ps_init2.c \
		ps_sort1.c ps_sort2.c ps_sort3.c ps_calculate.c \
		ps_deque.c ps_deque_utils.c \
		ps_command1.c ps_command2.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef SANITIZE
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

all : $(NAME)

bonus :$(NAME2)

$(LIBFT):
	@$(MAKE) -C ./libft all

%.o: %.c
	$(CC) $(CFLAGS) -I libft -c $< -o $@

ifeq ($(MAKECMDGOALS), bonus)
$(NAME2): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME2)
else
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
endif

clean : 
	@$(MAKE) -C ./libft clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean 
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(NAME2)
	

re : fclean all

sanitize : 
	make SANITIZE=1 re

.PHONY: all clean fclean re libft bonus