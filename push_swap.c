/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:29:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/27 22:31:20 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leak_check(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	// void		*sort_arr;
	
	int			cmd_cnt;

	cmd_cnt = 0;
	// sort_arr = 0;
	// print_arg(ac, av);
	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_exit(1);
	parsing_argv(av, &stack_a);
	// setting_order(&stack_a, ac);
	setting_order(&stack_a, &stack_b, ac);
	// make_sortarr(sort_arr, &stack_a, ac);
	if (stack_a.cnt <= 5)
		sort_under_five(&stack_a, &stack_b, &cmd_cnt);
	else
		sort_deque(&stack_a, &stack_b, &cmd_cnt);
	printf("stack a =============\n");
	print_deque(&stack_a);
	printf("stack b =============\n");
	print_deque(&stack_b);
	printf("cmd_cnt : %d\n", cmd_cnt);
	// system("leaks push_swap");
	return (0);
}
