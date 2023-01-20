/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:07:21 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 22:16:02 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_argv(char **av)
{
	int	i;

	i = 1;
	while(av[i])
	{
		printf("av[%d] : %s\n", i, av[i]);
		i++;
	}
}

void	print_error_exit(void)
{
	printf("Error\n");
	// system("leaks push_swap");
	exit(1);
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
		if (str[i] == '-')
			n *= -1;
		i++;
		if (!str[i])
			print_error_exit();
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0') * n;
		if (result < INT_MIN || result > INT_MAX)
			print_error_exit();
		i++;
	}
	return ((int)result);
}
