/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:08:43 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/13 21:37:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	**indexing_order(t_elem **order_arr, t_stack *stack_a, int ac)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack_a->head;
	order_arr = (t_elem **)malloc(sizeof(t_elem *) * (ac - 1));
	while (tmp)
	{
		order_arr[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	order_arr = sort_order(order_arr, ac);
	if (!check_arr(order_arr, ac))
		print_exit(1);
	return (order_arr);
}

t_elem	**sort_order(t_elem **order_arr, int ac)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (order_arr[i]->num > order_arr[j]->num)
				order_arr = swap_orderarr(order_arr, i, j);
			j++;
		}
		i++;
	}
	return (order_arr);
}

t_elem	**swap_orderarr(t_elem **order_arr, int i, int j)
{
	int		tmp_ord;
	t_elem	*tmp;

	tmp_ord = order_arr[i]->order;
	tmp = order_arr[i];
	order_arr[i]->order = order_arr[j]->order;
	order_arr[i] = order_arr[j];
	order_arr[j]->order = tmp_ord;
	order_arr[j] = tmp;
	tmp = 0;
	return (order_arr);
}

int	check_arr(t_elem **order_arr, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!order_arr)
		print_exit(1);
	while (j < (ac - 1))
	{
		if (order_arr[i]->num == order_arr[j]->num)
			return (0);
		if (order_arr[i]->order != j)
			return (0);
		i++;
		j++;
	}
	if (order_arr[i]->order != j)
		return (0);
	return (1);
}
