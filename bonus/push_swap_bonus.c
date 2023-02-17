/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:05:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/17 20:35:30 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_elem		**order_arr;
	char		*command;

	order_arr = NULL;
	command = 0;
	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_exit(1);
	parsing_argv(av, &stack_a);
	order_arr = indexing_order(order_arr, &stack_a, ac);
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		command = ps_strtrim(command, "\n");
		ps_command(command, &stack_a, &stack_b);
		free(command);
	}
	print_result(&stack_a, &stack_b);
	return (0);
}
