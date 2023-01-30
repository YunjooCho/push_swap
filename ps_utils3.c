/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:39:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/30 21:23:37 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}

void	setting_order(t_elem **order_arr, t_stack *stack_a, int ac)
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
	sort_arr(order_arr, ac);
	print_arr(order_arr, ac);
}

void	sort_arr(t_elem **order_arr, int ac)
{
	int		i;
	int		j;
	int		tmp_ord;
	t_elem	*tmp;
	
	i = 0;
	j = i + 1;
	tmp_ord = 0;
	tmp = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (order_arr[i]->num > order_arr[j]->num)
			{
				tmp_ord = order_arr[i]->order;
				tmp = order_arr[i];
				order_arr[i]->order = order_arr[j]->order;
				order_arr[i] = order_arr[j];
				order_arr[j]->order = tmp_ord;
				order_arr[j] = tmp;
				tmp = 0;
			}
			j++;
		}
		i++;
	}
}

void	print_arr(t_elem **order_arr, int ac)
{
	int	i;

	i = 0;
	while (i < (ac - 1))
	{
		// order_arr[i]->order = i + 1;
		printf("order_arr[%d] :%p, num : %d, order : %d\n", \
			i, order_arr[i], order_arr[i]->num, order_arr[i]->order);
		i++;
	}
}

