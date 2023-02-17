# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 18:29:41 by yunjcho           #+#    #+#              #
#    Updated: 2023/02/17 20:17:55 by yunjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_DIR = mandatory/
SRC = push_swap.c ps_utils.c ps_parse.c ps_index.c ps_init1.c ps_init2.c \
		ps_sort1.c ps_sort2.c ps_sort3.c ps_calculate.c \
		ps_deque.c ps_deque_utils.c \
		ps_command1.c ps_command2.c
SRC_BONUS_DIR = bonus/
SRC_BONUS = push_swap_bonus.c ps_utils1_bonus.c ps_utils2_bonus.c ps_parse_bonus.c ps_index_bonus.c ps_init1_bonus.c ps_init2_bonus.c \
		ps_sort1_bonus.c ps_sort2_bonus.c ps_sort3_bonus.c ps_calculate_bonus.c \
		ps_deque_bonus.c ps_deque_utils_bonus.c \
		ps_command1_bonus.c ps_command2_bonus.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS))
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(GNL_SRC:.c=.o)
LIBFT = libft/libft.a

ifdef SANITIZE
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

ifdef BONUS
	OBJS = $(SRCS_BONUS:.c=.o) $(GNL_SRC:.c=.o)
	NAME = $(NAME_BONUS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ -I libft -I get_next_line $<

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft all

clean : 
	@$(MAKE) -C ./libft clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

bonus :
	make BONUS=1 all

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re libft bonus sanitize