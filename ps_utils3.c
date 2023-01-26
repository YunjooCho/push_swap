/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:39:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 16:43:22 by yunjcho          ###   ########.fr       */
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

void	**make_sortarr(t_stack *stack, int ac)
{
	int		i;
	int		len;
	void	**sort_arr;
	t_elem	*tmp;

	i = 0;
	len = ac - 1;
	sort_arr = (void **)malloc(sizeof(void *) * len);
	tmp = stack->head;
	while (tmp)
	{
		sort_arr[i] = tmp;
		printf("sort_arr[%d] : %p, %p\n", i, sort_arr[i], tmp);
		i++;
		tmp = tmp->next;
	}
	return (sort_arr);
}