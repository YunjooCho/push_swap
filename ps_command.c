/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:46:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 18:42:04 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_command(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	str_len;
	
	if (!str || !stack_a || !stack_b)
		return ;
	// printf("a : %p %d b :%p %d\n", stack_a, stack_a->cnt, stack_b, stack_b->cnt);
	str_len = ft_strlen(str);
	if (!ft_strncmp(str, "sa", str_len))
		cmd_sasb(stack_a);
	else if (!ft_strncmp(str, "sb", str_len))
		cmd_sasb(stack_b);
	else if (!ft_strncmp(str, "ss", str_len))
	{
		cmd_sasb(stack_a);
		cmd_sasb(stack_b);
	}
	else if (!ft_strncmp(str, "pa", str_len))
		cmd_papb(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb", str_len))
		cmd_papb(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra", str_len))
		cmd_rarb(stack_a);
	else if (!ft_strncmp(str, "rb", str_len))
		cmd_rarb(stack_b);
	else if (!ft_strncmp(str, "rr", str_len))
	{
		cmd_rarb(stack_a);
		cmd_rarb(stack_b);
	}
	else if (!ft_strncmp(str, "rra", str_len))
		cmd_rrarrb(stack_a);
	else if (!ft_strncmp(str, "rrb", str_len))
		cmd_rrarrb(stack_b);
	else if (!ft_strncmp(str, "rrr", str_len))
	{
		cmd_rrarrb(stack_a);
		cmd_rrarrb(stack_b);
	}
}

void	cmd_sasb(t_stack *stack)
{
	t_elem *tmp_top;
	t_elem *tmp_sec;
	
	if (!stack->head || stack->cnt <= 1)
		return ;
	
	// printf("pre pop\n");
	// print_deque(stack);
	
	tmp_top = pop_front(stack);
	tmp_sec = pop_front(stack);
	
	// printf("pop\n");
	// if (stack->cnt == 0)
	// 	printf("noting %d\n", stack->cnt);
	// print_deque(stack);
	
	append_front(stack, tmp_top->num);
	append_front(stack, tmp_sec->num);
	
	printf("append\n");
	print_deque(stack);

	free(tmp_top);
	free(tmp_sec);
}

void	cmd_papb(t_stack *stack_from, t_stack *stack_to)
{
	t_elem	*tmp;
	
	tmp = 0;
	if (stack_from->cnt == 0)
		return ;
		
	printf("stack_from ========\n");
	print_deque(stack_from);
	printf("stack_to   ========\n");
	print_deque(stack_to);
	
	tmp = pop_front(stack_from);
	append_front(stack_to, tmp->num);
	free(tmp);
	
	printf("stack_from ========\n");
	print_deque(stack_from);
	printf("stack_to   ========\n");
	print_deque(stack_to);
}

void	cmd_rarb(t_stack *stack)
{
	t_elem	*tmp;

	tmp = 0;
	if (!stack->head || stack->cnt <= 1)
		return ;
	
	// printf("pre pop\n");
	// print_deque(stack);

	tmp = pop_front(stack);

	// printf("pop\n");
	// if (stack->cnt == 0)
	// 	printf("noting %d\n", stack->cnt);
	// print_deque(stack);

	append_back(stack, tmp->num);

	printf("append\n");
	print_deque(stack);

	free(tmp);
}

void	cmd_rrarrb(t_stack *stack)
{
	t_elem	*tmp;

	tmp = 0;
	if (!stack->head || stack->cnt <= 1)
		return ;
	
	// printf("pre pop\n");
	// print_deque(stack);

	tmp = pop_back(stack);
	append_front(stack, tmp->num);

	printf("append\n");
	print_deque(stack);

	free(tmp);
}