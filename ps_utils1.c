/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:07:21 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/26 15:51:36 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arg(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	printf("ac : %d\n", ac);
	while (av[i])
	{
		len = ft_strlen(av[i]);
		printf("av[%d] : %s\nav[%d] len : %d\n", i, av[i], i, len);
		i++;
	}
}

void	print_exit(int flag)
{
	if (flag == 1)
	{
		printf("Error\n");
		// system("leaks push_swap");
		exit(1);
	}
	else if (flag == 0)
	{
		printf("End\n");
		// system("leaks push_swap");
		exit(1) ;
	}
}

int	is_correct_arg(int ac)
{
	int	res;

	res = 0;
	if (ac <= 1)
		return (0);
	return (1);
}

void	parsing_argv(char **av, t_stack *stack)
{
	int	i;
	int	idx;

	i = 1;
	idx = 0;
	while (av[i])
	{
		// printf("str : %s str_len : %d\n", av[idx], str_len);
		split_atoi(av[i], stack, &idx);
		i++;
	}
}
