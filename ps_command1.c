/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:12:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 19:45:30 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_command(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	str_len;

	if (!str || !stack_a || !stack_b)
		return ;
	str_len = ft_strlen(str);
	if (str[0] == 's')
		command_swap(str, stack_a, stack_b, str_len);
	else if (str[0] == 'p')
		command_push(str, stack_a, stack_b, str_len);
	else if (str[0] == 'r')
		command_rotate(str, stack_a, stack_b, str_len);
	printf("%s\n", str);
}

void	command_swap(char *str, t_stack *stack_a, t_stack *stack_b, int str_len)
{
	if (!ft_strncmp(str, "sa", str_len))
		cmd_sasb(stack_a);
	else if (!ft_strncmp(str, "sb", str_len))
		cmd_sasb(stack_b);
	else if (!ft_strncmp(str, "ss", str_len))
	{
		cmd_sasb(stack_a);
		cmd_sasb(stack_b);
	}
}

void	command_push(char *str, t_stack *stack_a, t_stack *stack_b, int str_len)
{
	if (!ft_strncmp(str, "pa", str_len))
		cmd_papb(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb", str_len))
		cmd_papb(stack_a, stack_b);
}

void	command_rotate(char *str, t_stack *stack_a, t_stack *stack_b, \
	int str_len)
{
	if (!ft_strncmp(str, "ra", str_len))
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
