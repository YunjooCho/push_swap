/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:24:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 22:56:26 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_five(t_stack *stack_a, t_stack *stack_b, int *cmd_cnt)
{
	if (stack_a->cnt == 1)
		printf("%d\n", stack_a->cnt);
	else if (stack_a->cnt == 2)
		
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