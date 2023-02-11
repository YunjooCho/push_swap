/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:20:50 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/11 15:09:39 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sortarr(t_array **sort_arr, t_stack *stack, int ac)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack->head;
	sort_arr = (t_array **)malloc(sizeof(t_array *) * ac);
	if (!sort_arr)
		print_exit(1);
	while (sort_arr[i] && tmp)
	{
		sort_arr[i]->order = i;
		sort_arr[i]->elem = tmp;
		i++;
		tmp = tmp->next;
	}
}
