# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:32:34 by yunjcho           #+#    #+#              #
#    Updated: 2023/01/31 21:15:47 by yunjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
SRCS = push_swap.c ps_utils1.c ps_utils2.c ps_utils3.c \
       ps_deque.c ps_deque_utils.c \
	   ps_command.c ps_sort1.c ps_sort2.c
OBJS = $(SRCS:.c=.o) $(GNL_SRC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(GNL_SRC:.c=.o)

ifdef SANITIZE
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

ifdef BONUS
	OBJS = $(SRCS_BONUS:.c=.o)
endif

all : $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft all

%.o: %.c
	$(CC) $(CFLAGS) -I libft -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean : 
	@$(MAKE) -C ./libft clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

bonus :
	make BONUS=1 all

re : fclean all

sanitize : 
	make SANITIZE=1 re

.PHONY: all clean fclean re libft bonus