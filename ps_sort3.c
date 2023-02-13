/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:33:18 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 20:25:03 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_asc(t_stack *stack_a, t_stack *stack_b, t_info *move)
{
	int		idx;
	t_elem	*tmp;

	idx = 0;
	free(move);
	move = init_info(move);
	if (stack_a->head->order != 1)
	{
		tmp = stack_a->head;
		while (tmp)
		{
			if (tmp->order == 1)
			{
				idx = tmp->idx;
				if (idx <= stack_a->cnt / 2)
					move->a_cnt += tmp->idx;
				else
					move->a_cnt += (stack_a->cnt - tmp->idx) * -1;
			}
			tmp = tmp->next;
		}
	}
	move->total_cnt = move->a_cnt;
	moving_elem(stack_a, stack_b, move);
}

t_info	*check_movecnt(t_stack *stack_a, t_stack *stack_b)
{
	t_info	*min;
	t_info	*cur;
	t_elem	*tmp;

	min = 0;
	cur = 0;
	min = init_info(min);
	cur = init_info(cur);
	min->total_cnt = 2147483647;
	tmp = stack_b->head;
	while (tmp)
	{
		tmp->b_cnt = calcuate_movecnt(stack_b, tmp->idx);
		tmp->a_cnt = calculate_movecnta(stack_a, tmp);
		cur = calculate_totalcnt(tmp, cur);
		if (cur->total_cnt < min->total_cnt)
		{
			min->total_cnt = cur->total_cnt;
			min->a_cnt = cur->a_cnt;
			min->b_cnt = cur->b_cnt;
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
	int		a_mid;
	int		target_idx;
	t_elem	*cur;

	a_mid = stack_a->cnt / 2;
	cur = stack_a->head;
	target_idx = 0;
	while (cur->next)
	{
		if (tmp->order > stack_a->max)
		{
			if (stack_a->head->order == 1)
				return (target_idx);
			else if (cur->order == 1)
			{
				target_idx = cur->idx;
				break ;
			}
		}
		else if (tmp->order > cur->order && tmp->order < cur->next->order)
		{
			target_idx = cur->next->idx;
			break ;
		}
		cur = cur->next;
	}
	if (target_idx > a_mid)
		target_idx = (stack_a->cnt - target_idx) * -1;
	return (target_idx);
}

t_info *calculate_totalcnt(t_elem *tmp, t_info *cur)
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
	return (cur);
}
