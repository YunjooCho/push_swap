/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:05:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 22:20:22 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*command;
	
	command = 0;
	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_exit(1);
	parsing_argv(av, &stack_a);
	while (1)
	{
		write(0, command, 3);
		if (EOF)
			break;
		ps_command(command, &stack_a, &stack_b);
	}
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
	printf("stack a =============\n");
	print_deque(&stack_a);
	printf("stack b =============\n");
	print_deque(&stack_b);
	return (0);
}
