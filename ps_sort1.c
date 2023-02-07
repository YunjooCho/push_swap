/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/07 20:46:02 by yunjcho          ###   ########.fr       */
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
	int		b_mid;

	b_mid = stack_b->cnt / 2;
	check_movecnt(stack_a, stack_b, b_mid);
	
}

void	check_movecnt(t_stack *stack_a, t_stack *stack_b, int mid)
{
	int		min_idx;
	int		min_cnt;
	int		total_cnt;
	t_elem 	*tmp;

	min_idx = -1;
	min_cnt = 2147483647;
	total_cnt = 1; //pa
	tmp = stack_b->head;
	while (tmp)
	{
		// if (tmp->idx <= mid) //rb
		// 	tmp->b_cnt += tmp->idx;
		// else //rrb
		// 	tmp->b_cnt += stack_b->cnt - tmp->idx;
		calculate_movecntb(stack_b, tmp, mid);
		calculate_movecnta(stack_a, stack_b, tmp);
		total_cnt = tmp->a_cnt + tmp->b_cnt;
		if (total_cnt < min_cnt)
		{
			min_cnt = total_cnt;
			min_idx = tmp->idx;
		}
		tmp = tmp->next;
	}
}

int	calculate_movecntb(t_stack *stack_b, t_elem *tmp, int mid)
{
	if (tmp->idx <= mid) //rb
		tmp->b_cnt += tmp->idx;
	else //rrb
		tmp->b_cnt += stack_b->cnt - tmp->idx;
}

int	calculate_movecnta(t_stack *stack_a, t_stack *stack_b, t_elem *tmp)
{	
	int		a_mid;
	t_elem	*front;
	t_elem	*back;

	a_mid = stack_a->cnt / 2;
	front = stack_a->tail;
	back = stack_a->head;
}