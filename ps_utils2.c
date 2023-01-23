/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:04:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 16:41:31 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char chr)
{
	if (chr == '\t' || chr == '\n' || chr == '\v' \
		|| chr == '\f' || chr == '\r' || chr == ' ')
		return (0);
	return (1);
}

int	is_plus_minus(char *str, int i)
{
	int	idx;

	idx = i;
	if (str[idx] == '-')
		return (-1);
	idx++;
	if (!str[idx])
		return (0);
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
		if (!n)
			print_error_exit();
		i++;
	}
	if (!is_all_zero(str, i))
		print_error_exit();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error_exit();
		result = result * 10 + (str[i] - '0') * n;
		if (result < INT_MIN || result > INT_MAX)
			print_error_exit();
		i++;
	}
	return ((int)result);
}
