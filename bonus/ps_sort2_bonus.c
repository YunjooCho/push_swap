/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/17 19:21:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_two_elem(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->order > stack_a->head->next->order)
		ps_command("ra", stack_a, stack_b);
}

void	reverse_two_elem(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->head->order < stack_b->head->next->order)
		ps_command("rb", stack_a, stack_b);
}

void	sort_three_elem(t_stack *stack_a, t_stack *stack_b)
{
	int	check[3];
	int	len;

	len = 3;
	init_checkarr(stack_a, check, len);
	while (1)
	{
		if (check[0] && check[1] && check[2])
			return ;
		if (!check[0] && !check[1] && check[2])
		{
			ps_command("ra", stack_a, stack_b);
			init_checkarr(stack_a, check, len);
			continue ;
		}
		if (!check[1])
			ps_command("sa", stack_a, stack_b);
		if (!check[2])
			ps_command("rra", stack_a, stack_b);
		init_checkarr(stack_a, check, len);
	}
}

void	sort_four_elem(t_stack *stack_a, t_stack *stack_b)
{
	while (1)
	{
		if (stack_a->cnt == 4 && check_sort(stack_a))
			return ;
		if (stack_a->head->order == 1 && stack_a->cnt == 4)
			ps_command("pb", stack_a, stack_b);
		else if (stack_a->head->order == 3 || stack_a->head->order == 4)
		{
			ps_command("ra", stack_a, stack_b);
			continue ;
		}
		if (stack_a->head->next->order == 1)
		{
			ps_command("sa", stack_a, stack_b);
			continue ;
		}
		if (stack_a->cnt == 4 && stack_a->head->order == 2)
			ps_command("pb", stack_a, stack_b);
		if (stack_a->cnt == 3)
		{
			sort_three_elem(stack_a, stack_b);
			ps_command("pa", stack_a, stack_b);
		}
	}
}

void	sort_five_elem(t_stack *stack_a, t_stack *stack_b)
{
	int		cnt;
	int		pivot;

	cnt = 1;
	pivot = 3;
	while (cnt < pivot)
	{
		if (stack_a->cnt == 5 && check_sort(stack_a))
			return ;
		if (stack_a->head->order < pivot)
		{
			ps_command("pb", stack_a, stack_b);
			cnt++;
		}
		else
			ps_command("rra", stack_a, stack_b);
	}
	sort_three_elem(stack_a, stack_b);
	reverse_two_elem(stack_a, stack_b);
	ps_command("pa", stack_a, stack_b);
	ps_command("pa", stack_a, stack_b);
}
