/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:39:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 21:54:17 by yunjcho          ###   ########.fr       */
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

// int	find_pivot(t_stack *stack_a, int ac)
// {
// 	int		pivot;
// 	t_elem	*tmp;

// 	tmp = stack_a->head;
// 	pivot = tmp->num;
	
// }

void	sort_arr(void *arr, t_stack *stack_a, int ac)
{
	int	len;
	int	mid;
	// int	pivot;

	len = ac - 1;
	mid = ac / 2;
	printf("arr : %p, stack_a addr : %p\n", arr, stack_a);
	// quick_sort(0, mid, arr);

}

// void	quick_sort(void *arr, int left, int right)
// {
	
// }