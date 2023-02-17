/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:14:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 22:15:31 by yunjcho          ###   ########.fr       */
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

void	init_pivot(int *pia, int *pib, int len)
{
	int	div;
	int	mod;

	mod = len % 3;
	div = len / 3;
	*pia = 4;
	*pib = div * 2 + 1;
	if (mod == 2)
		(*pib)++;
}

void	init_info(t_info *info)
{
	info->total_cnt = 0;
	info->a_cnt = 0;
	info->b_cnt = 0;
	info->ab_cnt = 0;
	info->a_flag = 1;
	info->b_flag = 1;
	info->ab_flag = 1;
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
		init_abmove(move);
}

void	init_abmove(t_info *move)
{
	if (!move->a_flag && !move->b_flag)
		move->ab_flag = 0;
	if (move->a_cnt - move->b_cnt > 0)
	{
		move->ab_cnt = move->b_cnt;
		move->a_cnt = move->a_cnt - move->b_cnt;
		move->b_cnt = 0;
		move->total_cnt = move->ab_cnt + move->a_cnt + move->b_cnt;
	}
	else
	{
		move->ab_cnt = move->a_cnt;
		move->b_cnt = move->b_cnt - move->a_cnt;
		move->a_cnt = 0;
		move->total_cnt = move->ab_cnt + move->a_cnt + move->b_cnt;
	}
}
