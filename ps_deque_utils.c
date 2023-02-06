/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/06 20:26:45 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*malloc_deque(void)
// {
// 	t_stack	*deque;

// 	deque = (t_stack *)malloc(sizeof(t_stack));
// 	if (deque)
// 		init_deque(deque);
// 	return (deque);
// }

void	init_deque(t_stack *deque)
{
	deque->head = NULL;
	deque->tail = NULL;
	deque->cnt = 0;
}

void	init_element(t_elem *element, int num, int *order)
{
	element->num = num;
	element->idx = 0;
	element->order = *order;
	element->move_cnt = 0;
	element->prev = NULL;
	element->next = NULL;
	// printf("init_elem idx : %d, num : %d\n", element->idx, element->num);
}

void	free_deque(t_stack *deque)
{
	t_elem	*popped;

	popped = NULL;
	while (deque->cnt)
	{
		popped = pop_back(deque);
		free(popped);
	}
	// free(deque);
}

void	print_deque(t_stack *deque)
{
	t_elem	*tmp;

	tmp = deque->head;
	while (tmp)
	{
		printf("elem[%d] :%p, num : %d, idx: %d, order : %d, movcnt : %d, prev : %p, next : %p\n", \
			tmp->order, tmp, tmp->num, tmp->idx, tmp->order, tmp->move_cnt, tmp->prev, tmp->next);
		tmp = tmp->next;
	}
}
