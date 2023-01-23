/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 20:24:43 by yunjcho          ###   ########.fr       */
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
	deque->max_num = 0;
	deque->min_num = 0;
	deque->mid_num = 0;
	deque->cnt = 0;
	deque->all_cnt = 0;
}

void	init_element(t_elem *element, int num)
{
	element->num = num;
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
	// free(deque);
}

void	print_deque(t_stack *deque)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = deque->head;
	if (!tmp)
	{
		printf("deque max : %d, min : %d, mid : %d\n", \
			deque->max_num, deque->min_num, deque->mid_num);
	}
	while (tmp)
	{
		printf("elem[%d] :%p, num : %d, prev : %p, next : %p, max : %d, min : %d, mid : %d\n",
			i++, tmp, tmp->num, tmp->prev, tmp->next, deque->max_num, deque->min_num, deque->mid_num);
		tmp = tmp->next;
	}
}
