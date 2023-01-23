/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:04:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 15:33:57 by yunjcho          ###   ########.fr       */
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

// int	is_plus_minus(char chr)
// {
// 	if (chr == '+' || chr == '-')
// 	{
// 		if (chr == '-')
// 			n *= -1;
// 		i++;
// 		if (!str[i])
// 			print_error_exit();
// 	}
// }

int	ps_atoi(char *str)
{
	long long	i;
	long long	n;
	long long	result;

	i = 0;
	n = 1;
	result = 0;
	// if (!is_space(str[i]))
	// 	print_error_exit();
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
		if (!str[i])
			print_error_exit();
	}
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