/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:04:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 15:38:12 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_atoi(char *str, t_stack *stack, int *idx)
{
	char	**arr;
	int		res;
	int		i;

	arr = ft_split(str, ' ');
	// printf("split_arg arr : %p %s\n", arr, arr[0]);
	i = 0;
	if (!arr[i])
		print_exit(1);
	while (arr[i])
	{
		// printf("arr[%d] : %s , len : %zu\n", i, arr[i], ft_strlen(arr[i]));
		res = ps_atoi(arr[i]);
		append_back(stack, res, idx);
		(*idx)++;
		i++;
		// printf("res , %d, i : %d\n", res, i);
	}
	free_matrix(arr);
}

int	is_plus_minus(char *str, int i)
{
	int	idx;

	idx = i;
	if (!ft_isdigit(str[idx + 1]))
		print_exit(1);
	if (str[idx] == '-')
		return (-1);
	return (1);
}

int	is_all_zero(char *str, int i)
{
	int	idx;
	int	res;

	idx = i;
	res = 1;
	if (str[idx] != '0' || str[idx + 1] != '0')
		return (res);
	while (str[++idx])
	{
		if (str[idx] >= '1' && str[idx] <= '9')
			return (res);
	}
	res = 0;
	return (res);
}

int	ps_atoi(char *str)
{
	long long	i;
	long long	n;
	long long	result;

	i = 0;
	n = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		n = n * is_plus_minus(str, i);
		i++;
	}
	if (!is_all_zero(str, i))
		print_exit(1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_exit(1);
		result = result * 10 + (str[i] - '0') * n;
		if (result < INT_MIN || result > INT_MAX)
			print_exit(1);
		i++;
	}
	return ((int)result);
}
