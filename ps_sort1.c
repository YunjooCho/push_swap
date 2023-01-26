/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 14:59:18 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_five(t_stack *stack_a, t_stack *stack_b, int *cmd_cnt)
{
	printf("stack b addr : %p\n", stack_b);
	if (stack_a->cnt == 1)
		print_exit(0);
	else if (stack_a->cnt == 2)
		sort_two_elem(stack_a, cmd_cnt);
	// else if (stack_a->cnt == 3)
	// 	sort_tree_elem();
}

void	sort_deque(t_stack *stack_a, t_stack *stack_b, int *cmd_cnt)
{
	int	num;

	num = 0;
	while (stack_a->cnt)
	{
		// ps_command("pb", stack_a, stack_b);
		cmd_papb(stack_a, stack_b);
		cmd_cnt++;
	}
}