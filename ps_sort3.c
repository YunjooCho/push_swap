/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:33:18 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 21:53:22 by yunjcho          ###   ########.fr       */
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
	// printf("total_cnt : %d, ab_cnt : %d, a_cnt : %d, b_cnt : %d\n", move->total_cnt, move->ab_cnt, move->a_cnt, move->b_cnt);
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
			min = cur;
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

	target_idx = 0;
	cur = stack_a->head;
	while (cur->next)
	{
		if (tmp->order > stack_a->max)
		{
			if (stack_a->head->order == 1)
				return (0);
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
	return (calcuate_movecnt(stack_a, target_idx));
}

t_info *calculate_totalcnt(t_elem *tmp, t_info *cur)
{
	if (tmp->a_cnt < 0)
	{
		cur->total_cnt += tmp->a_cnt * -1;
		cur->a_cnt = tmp->a_cnt;
	}
	if (tmp->b_cnt < 0)
	{
		cur->total_cnt += tmp->b_cnt * -1;
		cur->b_cnt = tmp->b_cnt;
	}
	return (cur);
}
