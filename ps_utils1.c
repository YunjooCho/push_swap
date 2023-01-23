/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:07:21 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 18:20:19 by yunjcho          ###   ########.fr       */
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
		printf("av[%d] : %s\nav[%d] len : %d\n", i, av[i], i, len);
		i++;
	}
}

void	print_error_exit(void)
{
	printf("Error\n");
	system("leaks push_swap");
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

	idx = 1;
	res = 0;
	while (av[idx])
	{
		// printf("str : %s str_len : %d\n", av[idx], str_len);
		split_arg(av[idx], a);
		idx++;
	}
}

void	split_arg(char *str, t_stack *a)
{
	char	**arr;
	int		res;
	int		i;
	
	arr = ft_split(str, ' ');
	// printf("split_arg arr : %p %s\n", arr, arr[0]);
	i = 0;
	if (!arr[i])
		print_error_exit();
	while (arr[i])
	{
		// printf("arr : %s , len : %zu\n", arr[i], ft_strlen(arr[i]));
		res = ps_atoi(arr[i]);
		// printf("res : %d\n", res);
		append_back(a, res);
		i++;
	}
	free_matrix(arr);
}
