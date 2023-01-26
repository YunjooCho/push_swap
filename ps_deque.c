/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:58:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 17:51:23 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_front(t_stack *deque, int num, int *order)
{
	t_elem	*new_element;

	new_element = (t_elem *)malloc(sizeof(t_elem));
	if (!new_element)
		return ;
	init_element(new_element, num, order);
	if (!deque->head)
	{
		deque->head = new_element;
		deque->tail = new_element;
	}
	else
	{
		deque->head->prev = new_element;
		new_element->next = deque->head;
		deque->head = new_element;
	}
	deque->cnt++;
}

void	append_back(t_stack *deque, int num, int *order)
{
	t_elem	*new_element;

	new_element = (t_elem *)malloc(sizeof(t_elem));
	if (!new_element)
		return ;
	init_element(new_element, num, order);
	if (!deque->tail)
	{
		deque->head = new_element;
		deque->tail = new_element;
	}
	else
	{
		new_element->prev = deque->tail;
		deque->tail->next = new_element;
		deque->tail = new_element;
	}
	deque->cnt++;
}

t_elem	*pop_front(t_stack *deque)
{
	t_elem	*tmp;

	if (deque->cnt)
	{
		tmp = deque->head;
		deque->head = tmp->next;
		if (deque->head)
			deque->head->prev = 0;
		tmp->next = 0;
		deque->cnt--;
		if (deque->cnt == 0)
		{
			deque->head = 0;
			deque->tail = 0;
		}
		return (tmp);
	}
	return (0);
}

t_elem	*pop_back(t_stack *deque)
{
	t_elem	*tmp;

	if (deque->cnt)
	{
		tmp = deque->tail;
		deque->tail = tmp->prev;
		if (deque->tail)
			deque->tail->next = 0;
		tmp->prev = 0;
		deque->cnt--;
		if (deque->cnt == 0)
		{
			deque->head = 0;
			deque->tail = 0;
		}
		return (tmp);
	}
	return (0);
}
