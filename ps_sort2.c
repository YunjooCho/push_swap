/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/03 19:44:34 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stack *stack, t_elem **order_arr)
{
	t_elem *tmp;

	tmp = 0;
	if (stack->head->order > stack->head->next->order)
	{
		cmd_rarb(stack, "ra");
		order_arr[0] = stack->head;
		order_arr[1] = stack->tail;
	}
}

void	reverse_two_elem(t_stack *stack)
{
	if (stack->head->order < stack->head->next->order)
		cmd_rarb(stack, "ra");
}

void	sort_three_elem(t_stack *stack_a, t_elem **order_arr)
{
	int	check[3];
	int	len;

	len = 3;
	printf("three order_arr : %p\n", order_arr);
	init_checkarr(stack_a, check, len);
	while (1)
	{
		if (check[0] && check[1] && check[2])
			return ;
		if (!check[0] && !check[1] && check[2])
		{
			cmd_rarb(stack_a, "ra");
			init_checkarr(stack_a, check, len);
			continue ;
		}
		if (!check[1])
		{
			cmd_sasb(stack_a, "sa");
			init_checkarr(stack_a, check, len);
		}
		if (!check[2])
		{
			cmd_rrarrb(stack_a, "rra");
			init_checkarr(stack_a, check, len);
		}
	}
}

void	sort_four_elem(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr)
{
	while (1)
	{
		if (stack_a->cnt == 4 && check_sort(stack_a))
			return ; 
		if (stack_a->head->order == 1 && stack_a->cnt == 4)
			cmd_papb(stack_a, stack_b, "pb");
		else if (stack_a->head->order == 3 || stack_a->head->order == 4)
		{
			cmd_rarb(stack_a, "ra");
			continue ;
		}
		if (stack_a->head->next->order == 1)
		{
			cmd_sasb(stack_a, "sa");
			continue ;
		}
		if (stack_a->cnt == 4 && stack_a->head->order == 2)
			cmd_papb(stack_a, stack_b, "pb");
		if (stack_a->cnt == 3)
		{
			sort_three_elem(stack_a, order_arr);
			cmd_papb(stack_b, stack_a, "pa");
		}
	}
}

void	sort_five_elem(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr)
{
	int		cnt;
	int		pivot;

	cnt = 1;
	pivot = 3;
	while (cnt < pivot)
	{
		if (stack_a->cnt == 5 && check_sort(stack_a))
			return ; 
		if (stack_a->head->order < pivot)
		{
			cmd_papb(stack_a, stack_b, "pb");
			cnt++;
		}
		else
			cmd_rrarrb(stack_a, "rra");
	}
	sort_three_elem(stack_a, order_arr);
	reverse_two_elem(stack_b);
	cmd_papb(stack_b, stack_a, "pa");
	cmd_papb(stack_b, stack_a, "pa");
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

int	check_sort(t_stack *stack_a)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack_a->head;
	while (i < stack_a->cnt && tmp)
	{
		if (tmp->order != (i + 1))
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}