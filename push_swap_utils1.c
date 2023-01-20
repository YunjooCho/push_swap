/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:07:21 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 23:17:21 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arg(int ac, char **av)
{
	int	i;
	int len;

	i = 1;
	len = 0;
	printf("ac : %d\n", ac);
	while(av[i])
	{
		len = ft_strlen(av[i]);
		printf("av[%d] : %s, len : %d\n", i, av[i], len);
		i++;
	}
}

void	print_error_exit(void)
{
	printf("Error\n");
	// system("leaks push_swap");
	exit(1);
}

int		is_correct_arg(int ac)
{
	int	res;

	res = 0;
	if (ac <= 1)
		return (0);
	return (1);
}

void	parsing_argv(char **av, t_stack *a)
{
	int	idx;
	int	res;
	int	str_len;

	idx = 1;
	res = 0;
	str_len = 0;
	while (av[idx])
	{
		str_len = ft_strlen(av[idx]);
		// printf("str : %s str_len : %d\n", av[idx], str_len);
		split_arg(av[idx], a);
		idx++;
	}
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
		if (!ft_isdigit(str[i]))
			print_error_exit();
		result = result * 10 + (str[i] - '0') * n;
		if (result < INT_MIN || result > INT_MAX)
			print_error_exit();
		i++;
	}
	return ((int)result);
}
