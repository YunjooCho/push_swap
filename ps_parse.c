/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:05:20 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/14 17:59:41 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_argv(char **av, t_stack *stack)
{
	int	i;
	int	order;

	i = 1;
	order = 1;
	while (av[i])
	{
		split_atoi(av[i], stack, &order);
		i++;
	}
}

void	split_atoi(char *str, t_stack *stack, int *order)
{
	char	**arr;
	int		res;
	int		i;

	arr = ft_split(str, ' ');
	i = 0;
	if (!arr[i])
		print_exit(1);
	while (arr[i])
	{
		res = ps_atoi(arr[i]);
		append_back(stack, res, order);
		i++;
		(*order)++;
	}
	free_matrix(arr);
}

int	is_plus_minus(char *str, int i)
{
	int	idx;

	idx = i;
	if (!ft_isdigit(str[idx + 1]))
		print_exit(0);
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
