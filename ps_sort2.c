/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/28 19:28:07 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stack *stack, int *cmd_cnt)
{
	int		ord;
	t_elem	*tmp;

	ord = 0;
	tmp = stack->head;
	if (tmp->num > tmp->next->num)
	{
		ord = tmp->order;
		tmp->order = tmp->next->order;
		tmp->next->order = ord;
		cmd_rarb(stack);
		(*cmd_cnt)++;
	}
}

void	sort_tree_elem(t_stack *stack_a, int *cmd_cnt)
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

void	sort_four_elem(t_stack *stack_a, int *cmd_cnt)
{
	printf("stack_a : %p cmd_cnt : %d\n", stack_a, *cmd_cnt);
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
		if (j->num - i->num < 0)
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