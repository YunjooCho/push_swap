/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 20:14:50 by yunjcho          ###   ########.fr       */
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
	while (stack_a->cnt > 3)
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
	t_info	*move;

	while (stack_b->cnt)
	{
		move = check_movecnt(stack_a, stack_b);
		moving_elem(stack_a, stack_b, move);
	}
	sorting_asc(stack_a, stack_b, move);
}
