/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/09 23:38:30 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_five(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr)
{
	if (stack_a->cnt == 1)
		return ;
	else if (stack_a->cnt == 2)
		sort_two_elem(stack_a, stack_b, order_arr);
	else if (stack_a->cnt == 3)
		sort_three_elem(stack_a, stack_b, order_arr);
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
	sort_three_elem(stack_a, stack_b, order_arr);
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
			ps_command("pb", stack_a, stack_b);
			// cmd_papb(stack_a, stack_b, "pb");
			if (stack_b->cnt != 0)
			{
				// cmd_rarb(stack_b, "rb");
				ps_command("rb", stack_a, stack_b);
			}
		}
		else if (pia <= stack_a->head->order)
		{
			ps_command("pb", stack_a, stack_b);
			// cmd_papb(stack_a, stack_b, "pb");
		}
		else
		{
			ps_command("ra", stack_a, stack_b);
			// cmd_rarb(stack_a, "ra");
		}
	}
}

void	move_stacka(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*move_elem;

	while (stack_b->cnt)
	{
		move_elem = check_movecnt(stack_a, stack_b);
		moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	}
	
}

t_elem	*check_movecnt(t_stack *stack_a, t_stack *stack_b)
{
	int		min_cnt;
	int		total_cnt;
	t_elem 	*tmp;
	t_elem	*move_elem;
	// int savea = 2147483647;
	// int saveb = 2147483647;

	min_cnt = 2147483647;
	total_cnt = 0;
	tmp = stack_b->head;
	move_elem = stack_b->head;
	while (tmp) // a_count + b_count 비교 savea + saveb;
	{
		// total_cnt = 0;
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
	if (tmp->idx <= b_mid) //rb
		tmp->b_cnt += tmp->idx;
	else //rrb
		tmp->b_cnt += (stack_b->cnt - tmp->idx) * -1;
}

void	calculate_movecnta(t_stack *stack_a, t_elem *tmp)
{	
	int		a_mid;
	t_elem	*cur;
	
	a_mid = stack_a->cnt / 2;
	cur = stack_a->head;
	while (cur->next)
	{
		if (tmp->order > stack_a->max)
		{
			if (stack_a->head->order == 1)
			{
				tmp->a_cnt = 0;
				return ;
			}
			else
			{
				if (cur->order == 1)
				{
					if (cur->idx < a_mid)
						tmp->a_cnt = cur->idx;
					else
						tmp->a_cnt = (stack_a->cnt - tmp->idx) * -1;
					return ;
				}
			}
		}
		else
		{
			if (cur->order > tmp->order && cur->next->order < tmp->order)
			{
				if (cur->next->order < a_mid)
					tmp->a_cnt = cur->idx;
				else
					tmp->a_cnt = (stack_a->cnt - tmp->idx) * -1;
				return ;
			}
		}
		cur = cur->next;
	}
}

void	moving_elem(t_stack *stack_a, t_stack *stack_b, int a_cnt, int b_cnt)
{

	//-1 -3
	//-3 -2
	//3   0
	//0   3
	//3   6
	//4   2
	
	int	flag;
	int	ab_move;
	int	direction;

	flag = 1; // 0 : rrr,  1 : rr 
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
			a_cnt = ab_move - b_cnt;
			b_cnt = 0;
		}
		else
		{
			ab_move = a_cnt;
			a_cnt = 0;
			b_cnt = ab_move - a_cnt;
		}
	}
	else
	{
		if (a_cnt < 0)
		{
			flag = 0;
			a_cnt *= -1;
		}
		else
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
	ps_command("pa", stack_a, stack_b);
	while (a_cnt)
	{
		if (!flag)
			ps_command("rra", stack_a, stack_b);
		else
			ps_command("ra", stack_a, stack_b);
		a_cnt--;
	}
	
}
