/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:33:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 21:37:27 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_idxmax(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack->head;
	stack->max = -2147483648;
	while (tmp)
	{
		if (tmp->order > stack->max)
			stack->max = tmp->order;
		tmp->idx = i;
		i++;
		tmp = tmp->next;
	}
}
