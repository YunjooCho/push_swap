/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 20:24:44 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_stack *deque)
{
	deque->head = NULL;
	deque->tail = NULL;
	deque->max = 0;
	deque->cnt = 0;
}

void	init_element(t_elem *element, int num, int *order)
{
	element->num = num;
	element->idx = 0;
	element->order = *order;
	element->a_cnt = 0;
	element->b_cnt = 0;
	element->prev = NULL;
	element->next = NULL;
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
}

void	print_deque(t_stack *deque)
{
	t_elem	*tmp;

	tmp = deque->head;
	printf("deque max : %d\n", deque->max);
	while (tmp)
	{
		printf("elem[%d] :%p, num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
			tmp->order, tmp, tmp->num, tmp->idx, tmp->order, tmp->a_cnt, tmp->b_cnt, tmp->prev, tmp->next);
		tmp = tmp->next;
	}
}