/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:39:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 22:06:29 by yunjcho          ###   ########.fr       */
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

void	setting_order(t_stack *stack_a, int ac)
{
	int		i;
	void	**arr;
	t_elem	*tmp;

	i = 0;
	arr = (void **)malloc(sizeof(void *) * ac);
	tmp = stack_a->head;
	while (tmp)
	{
		arr[i] = tmp;
		tmp = tmp->next;
	}
	sort_arr(arr, stack_a, ac);
}

void	sort_arr(void *arr, t_stack *stack_a, int ac)
{
	int	len;
	int	mid;

	len = ac - 1;
	mid = ac / 2;
	printf("arr : %p, stack_a addr : %p\n", arr, stack_a);
	quick_sort(arr, 0, len);
}

void	quick_sort(void *arr, int left, int right) //고치기
{	int	pivot;

	pivot = 0;
	if (left >= right)
		return ;
	pivot = (left + right) / 2;

	quick_sort(arr, left, pivot);
	quick_sort(arr, pivot + 1, right);
}

// int	find_pivot(t_stack *stack_a, int ac)
// {
// 	int		pivot;
// 	t_elem	*tmp;

// 	tmp = stack_a->head;
// 	pivot = tmp->num;
	
// }