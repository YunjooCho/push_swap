/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/30 22:14:58 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stack *stack, t_elem **order_arr, int *cmd_cnt)
{
	t_elem	*tmp;

	tmp = stack->head;
	if (tmp->order > tmp->next->order)
	{
		cmd_rarb(stack);
		(*cmd_cnt)++;
	}
}

void	sort_three_elem(t_stack *stack_a, t_elem **order_arr, int *cmd_cnt)
{
	int	check[3];
	int	len;

	len = 3;
	init_checkarr(stack_a, check, len);
	while (1)
	{
		if (check[0] && check[1] && check[2])
			return ;
		if (!check[0] && !check[1] && check[2])
		{
			cmd_rarb(stack_a);
			(*cmd_cnt)++;
			init_checkarr(stack_a, check, len);
			continue ;
		}
		if (!check[1])
		{
			cmd_sasb(stack_a);
			(*cmd_cnt)++;
			init_checkarr(stack_a, check, len);
		}
		if (!check[2])
		{
			cmd_rrarrb(stack_a);
			(*cmd_cnt)++;
			init_checkarr(stack_a, check, len);
		}
	}
}

void	sort_four_elem(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr, int *cmd_cnt)
{
	int		mid;
	t_elem	*tmp;

	mid = 0;
	tmp = stack_a->head;
	if (tmp->order == 1)
	{
		cmd_papb(stack_a, stack_b);
		cmd_cnt++;
	}
	else if (tmp->order == 4)
	{	
		cmd_rrarrb(stack_a);
		cmd_cnt++;
	}
	if (tmp->next->order == 1)
	{
		cmd_sasb(stack_a);
		cmd_cnt++;
	}
	sort_tree_elem(stack_a, order_arr, cmd_cnt);
	cmd_papb(stack_b, stack_a);
	cmd_cnt++;
}

void	init_checkarr(t_stack *stack_a, int *check, int len)
{
	int		idx;
	t_elem	*i;
	t_elem	*j;

	idx = 0;
	i = stack_a->head;
	j = stack_a->tail;
	while (idx < len && j)
	{
		// printf("i : %d, j : %d\n", i->num, j->num);
		if (j->order - i->order < 0)
			check[idx] = 0;
		else
			check[idx] = 1;
		idx++;
		if (idx == 1)
		{
			j = stack_a->head->next;
			continue ;
		}
		i = i->next;
		j = j->next;
	}
	// printf("check[0] : %d\n", check[0]);
	// printf("check[1] : %d\n", check[1]);
	// printf("check[2] : %d\n", check[2]);
}