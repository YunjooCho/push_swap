/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/31 21:16:48 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_five(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr, int *cmd_cnt)
{
	if (stack_a->cnt == 1)
		return ;
	else if (stack_a->cnt == 2)
		sort_two_elem(stack_a, order_arr, cmd_cnt);
	else if (stack_a->cnt == 3)
		sort_three_elem(stack_a, order_arr, cmd_cnt);
	else if (stack_a->cnt == 4)
		sort_four_elem(stack_a, stack_b, order_arr, cmd_cnt);
	else if (stack_a->cnt == 5)
		sort_five_elem(stack_a, stack_b, order_arr, cmd_cnt);
}

void	sort_deque(t_stack *stack_a, t_stack *stack_b, int *cmd_cnt)
{
	int	num;

	num = 0;
	printf("sort_deque : %d\n", *cmd_cnt);
	printf("stack_a : %p\n", stack_a);
	printf("stack_b : %p\n", stack_b);
	// while (stack_a->cnt)
	// {
	// 	// ps_command("pb", stack_a, stack_b);
	// 	cmd_papb(stack_a, stack_b, "pa");
	// 	cmd_cnt++;
	// }
}