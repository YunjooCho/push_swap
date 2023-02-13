/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:33:18 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 22:35:49 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moving_elem(t_stack *stack_a, t_stack *stack_b, t_info *move)
{
	char	*rotate;

	rotate = 0;
	init_flag(move);
	while (move->total_cnt)
	{
		rotate = moving_rotate(move);
		ps_command(rotate, stack_a, stack_b);
		move->total_cnt--;
	}
	ps_command("pa", stack_a, stack_b);
}

char	*moving_rotate(t_info *move)
{
	char	*rotate;

	rotate = 0;
	if (move->ab_cnt)
	{
		rotate = "rr";
		if (!move->ab_flag)
			rotate = "rrr";
		move->ab_cnt--;
	}
	else if (move->b_cnt)
	{
		rotate = "rb";
		if (!move->b_flag)
			rotate = "rrb";
		move->b_cnt--;
	}
	else if (move->a_cnt)
	{
		rotate = "ra";
		if (!move->a_flag)
			rotate = "rra";
		move->a_cnt--;
	}
	return (rotate);
}

void	sorting_asc(t_stack *stack_a, t_stack *stack_b, t_info *move)
{
	int		idx;
	t_elem	*tmp;

	idx = 0;
	init_info(move);
	if (stack_a->head->order != 1)
	{
		tmp = stack_a->head;
		while (tmp)
		{
			if (tmp->order == 1)
			{
				idx = tmp->idx;
				if (idx <= stack_a->cnt / 2)
					move->a_cnt = tmp->idx;
				else
					move->a_cnt = (stack_a->cnt - tmp->idx) * -1;
			}
			tmp = tmp->next;
		}
	}
	move->total_cnt = move->a_cnt;
	moving_elem(stack_a, stack_b, move);
}
