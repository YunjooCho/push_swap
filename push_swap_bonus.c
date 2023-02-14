/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:05:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 22:39:15 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_elem		**order_arr;
	char		*command;
	int			rbyte;
	
	order_arr = NULL;
	command = 0;
	rbyte = 0;
	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_exit(1);
	parsing_argv(av, &stack_a);
	order_arr = indexing_order(order_arr, &stack_a, ac);
	while (1)
	{
		command = get_next_line(0);
		command = ft_strtrim(command, "\n");
		ps_command(command, &stack_a, &stack_b);
		if (EOF)
			break;
	}
	printf("stack a =============\n");
	print_deque(&stack_a);
	printf("stack b =============\n");
	print_deque(&stack_b);
	if (!check_sort(&stack_a))
	{
		ft_putendl_fd("KO", 1);
		print_exit(0);
	}
	else if (check_sort(&stack_a) && !stack_b.cnt)
	{
		ft_putendl_fd("OK", 1);
		print_exit(0);
	}
	system("leaks push_swap_bonus");
	return (0);
}
