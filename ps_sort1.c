/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/03 21:27:28 by yunjcho          ###   ########.fr       */
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

void	sort_deque(t_stack *stack_a, t_stack *stack_b, int ac)
{
	int	pia;
	int	pib;
	int cnt[3];
}