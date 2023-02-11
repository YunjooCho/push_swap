/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:33:18 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 15:33:41 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_asc(t_stack *stack_a)
{
	int 	idx;
	int 	cnt;
	int		flag;
	t_elem	*tmp;

	idx = 0;
	cnt = 0;
	flag = 1;
	if (stack_a->head->order != 1)
	{
		tmp = stack_a->head;
		while (tmp)
		{
			if (tmp->order == 1)
			{
				idx = tmp->idx;
				if (idx <= stack_a->cnt / 2)
					cnt += tmp->idx;
				else
					cnt += (stack_a->cnt - tmp->idx) * -1;
			}
			tmp = tmp->next;
		}
	}
	if (cnt < 0)
	{
		flag = 0;
		cnt *= -1;
	}
	while (cnt)
	{
		if (!flag)
			ps_command("rra", stack_a, stack_b);
		else
			ps_command("ra", stack_a, stack_b);
		cnt--;
	}
}

t_elem	*check_movecnt(t_stack *stack_a, t_stack *stack_b)
{
	int		min_cnt;
	int		total_cnt;
	t_elem 	*tmp;
	t_elem	*move_elem;

	min_cnt = 2147483647;
	total_cnt = 0;
	tmp = stack_b->head;
	move_elem = stack_b->head;
	while (tmp)
	{
		calculate_movecntb(stack_b, tmp);
		calculate_movecnta(stack_a, tmp);
		if (tmp->a_cnt < 0)
			total_cnt += tmp->a_cnt * -1;
		else if (tmp->b_cnt < 0)
			total_cnt += tmp->b_cnt * -1;
		else
			total_cnt = tmp->a_cnt + tmp->b_cnt;
		if (total_cnt < min_cnt)
		{
			move_elem = tmp;
			min_cnt = total_cnt;
		}
		tmp = tmp->next;
	}
	return (move_elem);
}

void	calculate_movecntb(t_stack *stack_b, t_elem *tmp)
{
	int		b_mid;

	b_mid = stack_b->cnt / 2;
	tmp->b_cnt = 0;
	if (tmp->idx <= b_mid)
		tmp->b_cnt += tmp->idx;
	else
		tmp->b_cnt += (stack_b->cnt - tmp->idx) * -1;
}

void	calculate_movecnta(t_stack *stack_a, t_elem *tmp)
{	
	int		a_mid;
	t_elem	*cur;
	
	a_mid = stack_a->cnt / 2;
	cur = stack_a->head;
	tmp->a_cnt = 0;
	while (cur->next)
	{
		if (tmp->order > stack_a->max)
		{
			if (stack_a->head->order == 1)
			{
				tmp->a_cnt = 0;
				break ;
			}
			else if (cur->order == 1)
			{
				if (cur->idx <= a_mid)
					tmp->a_cnt = cur->idx;
				else
					tmp->a_cnt = (stack_a->cnt - cur->idx) * -1;
				break ;
			}
		}
		else
		{
			if (tmp->order > cur->order && tmp->order < cur->next->order)
			{
				if (cur->next->idx <= a_mid)
					tmp->a_cnt = cur->next->idx;
				else
					tmp->a_cnt = (stack_a->cnt - cur->next->idx) * -1;
				break ;
			}
		}
		cur = cur->next;
	}
}

void	moving_elem(t_stack *stack_a, t_stack *stack_b, int a_cnt, int b_cnt)
{
	int	flag;
	int	ab_move;
	int	direction;

	flag = 1;
	direction = a_cnt * b_cnt;
	ab_move = 0;
	if (direction > 0)
	{
		if (a_cnt < 0 && b_cnt < 0)
		{
			flag = 0;
			a_cnt *= -1;
			b_cnt *= -1;
		}
		if (a_cnt - b_cnt > 0)
		{
			ab_move = b_cnt;
			a_cnt = a_cnt - b_cnt;
			b_cnt = 0;
		}
		else
		{
			ab_move = a_cnt;
			b_cnt = b_cnt - a_cnt;
			a_cnt = 0;
		}
	}
	else
	{
		if (a_cnt < 0)
		{
			flag = 0;
			a_cnt *= -1;
		}
		else if (b_cnt < 0)
		{
			flag = 0;
			b_cnt *= -1;
		}
	}
	while (ab_move)
	{
		if (!flag)
			ps_command("rrr", stack_a, stack_b);
		else
			ps_command("rr", stack_a, stack_b);
		ab_move--;
	}
	while (b_cnt)
	{
		if (!flag)
			ps_command("rrb", stack_a, stack_b);
		else
			ps_command("rb", stack_a, stack_b);
		b_cnt--;
	}
	while (a_cnt)
	{
		if (!flag)
			ps_command("rra", stack_a, stack_b);
		else
			ps_command("ra", stack_a, stack_b);
		a_cnt--;
	}
	ps_command("pa", stack_a, stack_b);
}
