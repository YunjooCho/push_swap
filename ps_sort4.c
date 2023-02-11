/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:03:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 21:28:03 by yunjcho          ###   ########.fr       */
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
	int		flag;
	char	*str;

	flag = 1;
	if (move->a_cnt * move->b_cnt> 0)
		calculate_abmovecnt(move, &flag);
	while (move->total_cnt)
	{
		printf("total_cnt : %d, ab_cnt : %d, a_cnt : %d, b_cnt : %d\n", move->total_cnt, move->ab_cnt, move->a_cnt, move->b_cnt);
		if (move->ab_cnt)
		{
			str = "rr";
			move->ab_cnt--;
		}
		else if (move->b_cnt)
		{
			str = "rb";
			move->b_cnt--;
		}
		else if (move->a_cnt)
		{
			str = "ra";
			move->a_cnt--;
		}
		if (!flag)
			str = ft_strjoin("r", str);
		ps_command(str, stack_a, stack_b);
		move->total_cnt--;
	}
	ps_command("pa", stack_a, stack_b);
}

void	abs_cnt(int	*a_cnt, int *b_cnt, int *flag)
{
	*flag = 1;
	if (*a_cnt < 0)
	{
		*a_cnt *= -1;
		*flag = 0;
	}
	if (*b_cnt < 0)
	{
		*b_cnt *= -1;
		*flag = 0;
	}
}

void	calculate_abmovecnt(t_info *move, int *flag)
{
	int	a_cnt;
	int	b_cnt;

	a_cnt = move->a_cnt;
	b_cnt = move->b_cnt;
	abs_cnt(&a_cnt, &b_cnt, flag);
	if (a_cnt - b_cnt > 0)
	{
		move->total_cnt = b_cnt;
		move->a_cnt = a_cnt - b_cnt;
		move->b_cnt = 0;
	}
	else
	{
		move->total_cnt = a_cnt;
		move->b_cnt = b_cnt - a_cnt;
		move->a_cnt = 0;
	}
}
