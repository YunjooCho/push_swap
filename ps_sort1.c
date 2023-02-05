/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/05 20:36:44 by yunjcho          ###   ########.fr       */
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
	printf("pia : %d, pib : %d\n", pia, pib);
	move_stackb(stack_a, stack_b, pia, pib);
	sort_three_elem(stack_a, order_arr);
	// move_stacka(stack_a, stack_b, pia, pib);
}

void	init_pivot(int *pia, int *pib, int ac)
{
	int	div;
	int	mod;

	mod = (ac - 1) % 3;
	div = (ac - 1) / 3;
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
			cmd_papb(stack_a, stack_b, "pb");
		else if (pia <= stack_a->head->order)
		{
			cmd_papb(stack_a, stack_b, "pb");
			cmd_rarb(stack_b, "rb");
		}
		else
			cmd_rarb(stack_a, "ra");
	}
}

void	move_stacka(t_stack *stack_a, t_stack *stack_b, int pia, int pib)
{
	while (stack_b->cnt)
	{
		cmd_papb(stack_b, stack_a, "pa");
		if (stack_a->head->order == stack_a->cnt)
			cmd_rarb(stack_a, "ra");
		else if (stack_a->cnt != 4)
		{
			if (stack_a->head->order > stack_a->head->next->order)
				cmd_sasb(stack_a, "sa");
		}
	}
}