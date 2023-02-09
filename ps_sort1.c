/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/10 05:06:36 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->cnt == 1)
		return ;
	else if (stack_a->cnt == 2)
		sort_two_elem(stack_a, stack_b);
	else if (stack_a->cnt == 3)
		sort_three_elem(stack_a, stack_b);
	else if (stack_a->cnt == 4)
		sort_four_elem(stack_a, stack_b);
	else if (stack_a->cnt == 5)
		sort_five_elem(stack_a, stack_b);
}

void	sort_above_five(t_stack *stack_a, t_stack *stack_b)
{
	int	pia;
	int	pib;
	int	len;
	
	pia = 0;
	pib = 0;
	len = stack_a->cnt;
	init_pivot(&pia, &pib, len);
	move_stackb(stack_a, stack_b, pia, pib);
	sort_three_elem(stack_a, stack_b);
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
			if (stack_b->cnt != 0)
				ps_command("rb", stack_a, stack_b);
		}
		else if (pia <= stack_a->head->order)
			ps_command("pb", stack_a, stack_b);
		else
			ps_command("ra", stack_a, stack_b);
	}
}

void	move_stacka(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*move_elem;

	move_elem = check_movecnt(stack_a, stack_b);
	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	move_elem = check_movecnt(stack_a, stack_b);
	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	move_elem = check_movecnt(stack_a, stack_b);
	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	move_elem = check_movecnt(stack_a, stack_b);
	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	move_elem = check_movecnt(stack_a, stack_b);
	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);	
	move_elem = check_movecnt(stack_a, stack_b);
	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	move_elem = check_movecnt(stack_a, stack_b);	
	printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
		move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	// moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	
	//TODO - 디버깅 위치
	// while (stack_b->cnt)
	// {
	// 	move_elem = check_movecnt(stack_a, stack_b);
	// 	// printf("move_elem num : %d, idx: %d, order : %d, a_cnt : %d, b_cnt : %d, prev : %p, next : %p\n", \
	// 	// 	move_elem->num, move_elem->idx, move_elem->order, move_elem->a_cnt, move_elem->b_cnt, move_elem->prev, move_elem->next);
	// 	moving_elem(stack_a, stack_b, move_elem->a_cnt, move_elem->b_cnt);
	// }

	// int idx = 0;
	// int cnt = 0;
	// if (stack_a->head->order != 1)
	// {
	// 	move_elem = stack_a->head;
	// 	while (move_elem)
	// 	{
	// 		if (move_elem->order == 1)
	// 		{
	// 			idx = move_elem->idx;
	// 			if (idx <= stack_a->cnt / 2)
	// 				cnt += move_elem->idx;
	// 			else
	// 				cnt += (stack_a->cnt - move_elem->idx) * -1;
	// 		}
	// 		move_elem = move_elem->next;
	// 	}
	// }
	// int flag = 1;
	// if (cnt < 0)
	// {
	// 	flag = 0;
	// 	cnt *= -1;
	// }
	// while (cnt)
	// {
	// 	if (!flag)
	// 		ps_command("rra", stack_a, stack_b);
	// 	else
	// 		ps_command("ra", stack_a, stack_b);
	// 	cnt--;
	// }
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
			printf("here\n");
			if (tmp->order > cur->order && tmp->order < cur->next->order)
			{
				if (cur->next->order <= a_mid)
					tmp->a_cnt = cur->idx;
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
