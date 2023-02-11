/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:13:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 15:21:35 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_sasb(t_stack *stack)
{
	t_elem	*tmp_top;
	t_elem	*tmp_sec;

	if (!stack->head || stack->cnt <= 1)
		return ;
	tmp_top = pop_front(stack);
	tmp_sec = pop_front(stack);
	append_front(stack, tmp_top->num, &tmp_top->order);
	append_front(stack, tmp_sec->num, &tmp_sec->order);
	free(tmp_top);
	free(tmp_sec);
	init_idxmax(stack);
}

void	cmd_papb(t_stack *stack_from, t_stack *stack_to)
{
	t_elem	*tmp;

	tmp = 0;
	if (stack_from->cnt == 0)
		return ;
	tmp = pop_front(stack_from);
	append_front(stack_to, tmp->num, &tmp->order);
	free(tmp);
	init_idxmax(stack_from);
	init_idxmax(stack_to);
}

void	cmd_rarb(t_stack *stack)
{
	t_elem	*tmp;

	tmp = 0;
	if (!stack->head || stack->cnt <= 1)
		return ;
	tmp = pop_front(stack);
	append_back(stack, tmp->num, &tmp->order);
	free(tmp);
	init_idxmax(stack);
}

void	cmd_rrarrb(t_stack *stack)
{
	t_elem	*tmp;

	tmp = 0;
	if (!stack->head || stack->cnt <= 1)
		return ;
	tmp = pop_back(stack);
	append_front(stack, tmp->num, &tmp->order);
	free(tmp);
	init_idxmax(stack);
}

void	init_idxmax(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack->head;
	stack->max = -2147483648;
	while (tmp)
	{
		if (tmp->order > stack->max)
			stack->max = tmp->order;
		tmp->idx = i;
		i++;
		tmp = tmp->next;
	}
}
