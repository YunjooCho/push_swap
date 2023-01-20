/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:23:29 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 22:17:04 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_DEQUE_H
# define PUSH_SWAP_DEQUE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_elem
{
	int				num;
	struct s_elem	*prev;
	struct s_elem	*next;
}	t_elem;

typedef struct s_stack
{
	t_elem	*head;
	t_elem	*tail;
	int		cnt;
}	t_stack;

t_stack	*malloc_deque(void);
void	init_deque(t_stack *deque);
void	init_element(t_elem *element, int val);
void	append_front(t_stack *deque, int val);
void	append_back(t_stack *deque, int val);
t_elem	*pop_front(t_stack *deque);
t_elem	*pop_back(t_stack *deque);
void	free_deque(t_stack *deque);
void	print_deque(t_stack *deque);

#endif