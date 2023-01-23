/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:29:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 17:30:30 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void leak_check(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	
	print_arg(ac, av);

	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_error_exit();
	// system("leaks push_swap");
	parsing_argv(av, &stack_a);
	// print_deque(&stack_a);
	// print_deque(&stack_b);
	//Sort
	// ps_command("sa", &stack_a, &stack_b);
	ps_command("pb", &stack_a, &stack_b);
	ps_command("pb", &stack_a, &stack_b);
	ps_command("pa", &stack_a, &stack_b);
	// system("leaks push_swap");

	return (0);
}
