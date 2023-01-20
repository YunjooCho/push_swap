/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:29:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 22:56:19 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	
	print_arg(ac, av);

	init_deque(&stack_a);
	init_deque(&stack_b);
	if (!is_correct_arg(ac))
		print_error_exit();
	parsing_argv(av, &stack_a);
	// system("leaks push_swap");
	print_deque(&stack_a);
	print_deque(&stack_b);
	//Sort

	return (0);
}
