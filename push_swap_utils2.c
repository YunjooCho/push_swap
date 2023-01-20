/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:04:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 23:23:19 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_arg(char *str, t_stack *a)
{
	char	**arr;
	int		res;
	int		i;
	
	arr = ft_split(str, ' ');
	i = 0;
	while (arr[i])
	{
		// printf("arr : %s , len : %zu\n", arr[i], ft_strlen(arr[i]));
		res = ps_atoi(arr[i]);
		// printf("res : %d\n", res);
		append_back(a, res);
		i++;
	}
}