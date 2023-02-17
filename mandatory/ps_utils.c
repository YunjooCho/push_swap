/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:07:21 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 22:18:37 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_exit(int flag)
{
	if (flag == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else if (flag == 0)
		exit(1);
}

int	is_correct_arg(int ac)
{
	if (ac <= 1)
		return (0);
	return (1);
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

void	free_orderarr(t_elem **order_arr)
{
	int	idx;

	idx = 0;
	while (order_arr[idx])
	{
		free(order_arr[idx]);
		idx++;
	}
	free(order_arr);
}
