/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:29:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/06 17:17:29 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_elem		**order_arr;

	order_arr = NULL;
	// print_arg(ac, av);
	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_exit(1);
	parsing_argv(av, &stack_a);
	order_arr = setting_order(order_arr, &stack_a, ac);
	if (stack_a.cnt <= 5)
		sort_under_five(&stack_a, &stack_b, order_arr);
	else
		sort_above_five(&stack_a, &stack_b, order_arr);
	printf("stack a =============\n");
	print_deque(&stack_a);
	printf("stack b =============\n");
	print_deque(&stack_b);
	// system("leaks push_swap");
	return (0);
}

// |wc -l