/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 19:15:44 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stack *stack, int *cmd_cnt)
{
	int		ord;
	t_elem	*tmp;

	ord = 0;
	tmp = stack->head;
	if (tmp->num > tmp->next->num)
	{
		ord = tmp->order;
		tmp->order = tmp->next->order;
		tmp->next->order = ord;
		cmd_rarb(stack);
		(*cmd_cnt)++;
	}
}

// void	sort_tree_elem(t_stack *stack, int *cmd_cnt)
// {
	
// }