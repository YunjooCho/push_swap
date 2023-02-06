/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/06 20:37:04 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_five(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr)
{
	if (stack_a->cnt == 1)
		return ;
	else if (stack_a->cnt == 2)
		sort_two_elem(stack_a, order_arr);
	else if (stack_a->cnt == 3)
		sort_three_elem(stack_a, order_arr);
	else if (stack_a->cnt == 4)
		sort_four_elem(stack_a, stack_b, order_arr);
	else if (stack_a->cnt == 5)
		sort_five_elem(stack_a, stack_b, order_arr);
}

void	sort_above_five(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr)
{
	int	pia;
	int	pib;
	int	len;
	
	pia = 0;
	pib = 0;
	len = stack_a->cnt;
	init_pivot(&pia, &pib, len);
	move_stackb(stack_a, stack_b, pia, pib);
	sort_three_elem(stack_a, order_arr);
	move_stacka(stack_a, stack_b);
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

void	move_stackb(t_stack *stack_a, t_stack *stack_b, int pia, int pib)
{
	while (stack_a->cnt > 3) //TODO - 왜 3인지??
	{
		if (stack_a->head->order >= pib)
		{
			cmd_papb(stack_a, stack_b, "pb");
			if (stack_b->cnt != 0)
				cmd_rarb(stack_b, "rb");
		}
		else if (pia <= stack_a->head->order)
			cmd_papb(stack_a, stack_b, "pb");
		else
			cmd_rarb(stack_a, "ra");
	}
}

void	move_stacka(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a;
	min_movecnt(stack_b);
}

void	min_movecnt(t_stack *stack_b)
{
	int		min_idx;
	int		a_cnt;
	int		b_cnt;
	int		mid;
	t_elem 	*tmp;

	min_idx = -1;
	a_cnt = 0;
	b_cnt = 1;//pa
	mid = stack_b->cnt / 2;
	tmp = stack_b->head;
	while (tmp->next)
	{
		b_cnt = 1;//pa
		if (tmp->idx <= mid)
			b_cnt += tmp->idx;
		else
			b_cnt += stack_b->cnt - tmp->idx;
		tmp->move_cnt = b_cnt;
		tmp = tmp->next;
	}
	tmp->move_cnt = 1;
}