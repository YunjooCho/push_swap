/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:20:50 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 20:08:35 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	**sort_arr(t_elem **order_arr, int ac)
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

// void	free_orderarr(t_elem **order_arr, int ac)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (ac - 1))
// 	{
// 		if (order_arr[i])
// 			free(order_arr[i]);
// 		i++;
// 	}
// 	free(order_arr);
// }