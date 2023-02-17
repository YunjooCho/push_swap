/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:13:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 22:16:37 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	check_movecnt(t_stack *stack_a, t_stack *stack_b)
{
	t_info	min;
	t_info	cur;
	t_elem	*tmp;

	init_info(&min);
	init_info(&cur);
	min.total_cnt = 2147483647;
	tmp = stack_b->head;
	while (tmp)
	{
		tmp->b_cnt = calcuate_movecnt(stack_b, tmp->idx);
		tmp->a_cnt = calculate_movecnta(stack_a, tmp);
		calculate_totalcnt(tmp, &cur);
		if (cur.total_cnt < min.total_cnt)
		{
			min.total_cnt = cur.total_cnt;
			min.a_cnt = cur.a_cnt;
			min.b_cnt = cur.b_cnt;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	calcuate_movecnt(t_stack *stack, int target_idx)
{
	int	mid;
	int	cnt;

	cnt = 0;
	mid = stack->cnt / 2;
	if (target_idx <= mid)
		cnt = target_idx;
	else
		cnt = (stack->cnt - target_idx) * -1;
	return (cnt);
}

int	calculate_movecnta(t_stack *stack_a, t_elem *tmp)
{	
	int		target_idx;
	t_elem	*cur;

	cur = stack_a->head;
	target_idx = 0;
	while (cur->next)
	{
		if (tmp->order > stack_a->max)
		{
			if (stack_a->head->order == 1)
				return (target_idx);
			else if (cur->order == 1)
				target_idx = cur->idx;
		}
		else if (tmp->order > cur->order && tmp->order < cur->next->order)
			target_idx = cur->next->idx;
		cur = cur->next;
	}
	return (calcuate_movecnt(stack_a, target_idx));
}

void	calculate_totalcnt(t_elem *tmp, t_info *cur)
{
	cur->total_cnt = 0;
	cur->a_cnt = tmp->a_cnt;
	cur->b_cnt = tmp->b_cnt;
	if (tmp->a_cnt < 0)
		cur->a_cnt *= -1;
	if (tmp->b_cnt < 0)
		cur->b_cnt *= -1;
	cur->total_cnt = cur->a_cnt + cur->b_cnt;
	cur->a_cnt = tmp->a_cnt;
	cur->b_cnt = tmp->b_cnt;
}
