/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:03:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 20:08:58 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_checkarr(t_stack *stack_a, int *check, int len)
{
	int		idx;
	t_elem	*i;
	t_elem	*j;

	idx = 0;
	i = stack_a->head;
	j = stack_a->tail;
	while (idx < len && j)
	{
		if (j->order - i->order < 0)
			check[idx] = 0;
		else
			check[idx] = 1;
		idx++;
		if (idx == 1)
		{
			j = stack_a->head->next;
			continue ;
		}
		i = i->next;
		j = j->next;
	}
}

int	check_sort(t_stack *stack_a)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack_a->head;
	while (i < stack_a->cnt && tmp)
	{
		if (tmp->order != (i + 1))
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	moving_elem(t_stack *stack_a, t_stack *stack_b, t_info *move)
{
	char	*rotate;

	rotate = 0;	
	init_flag(move);
	while (move->total_cnt)
	{
		if (move->ab_cnt)
		{
			rotate = "rr";
			if (!move->ab_flag)
				rotate = ft_strjoin("r", rotate);
			move->ab_cnt--;
		}
		else if (move->b_cnt)
		{
			rotate = "rb";
			if (!move->b_flag)
				rotate = ft_strjoin("r", rotate);
			move->b_cnt--;
		}
		else if (move->a_cnt)
		{
			rotate = "ra";
			if (!move->a_flag)
				rotate = ft_strjoin("r", rotate);
			move->a_cnt--;
		}
		ps_command(rotate, stack_a, stack_b);
		move->total_cnt--;
	}
	ps_command("pa", stack_a, stack_b);
}

void	init_flag(t_info *move)
{
	if (move->a_cnt < 0)
	{
		move->a_cnt *= -1;
		move->a_flag = 0;
	}
	if (move->b_cnt < 0)
	{
		move->b_cnt *= -1;
		move->b_flag = 0;
	}
	if (move->a_flag == move->b_flag)
	{
		if (!move->a_flag && !move->b_flag)
			move->ab_flag = 0;
		if (move->a_cnt - move->b_cnt > 0)
		{
			move->ab_cnt = move->b_cnt;
			move->a_cnt = move->a_cnt - move->b_cnt;
			move->b_cnt = 0;
		}
		else
		{
			move->ab_cnt = move->a_cnt;
			move->b_cnt = move->b_cnt - move->a_cnt;
			move->a_cnt = 0;
		}
	}
}
