/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:39:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 21:45:13 by yunjcho          ###   ########.fr       */
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

t_elem	**setting_order(t_elem **order_arr, t_stack *stack_a, int ac)
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
	order_arr = sort_arr(order_arr, ac);
	if (!check_arr(order_arr, ac))
		print_exit(1);
	return (order_arr);
}

t_info	*init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	info->total_cnt = 0;
	info->a_cnt = 0;
	info->b_cnt = 0;
	info->ab_cnt = 0;
	return (info);
}