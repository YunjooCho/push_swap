/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:37:10 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 22:13:34 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "limits.h"

int	is_correct_arg(int ac, char **av, t_stack *a)
{
	int	idx;
	int	res;

	idx = 1;
	res = -1;
	if (ac <= 1)
		return (0);
	while (av[idx])
	{
		// if (!ft_isint(av[idx]))
		// 	return (0);
		res = ps_atoi(av[idx]);
		printf("res : %d\n", res);
		append_back(a, res);
		idx++;
	}
	return (1);
}

// int	ft_isint(char *str)
// {
// 	int	len;
// 	int	res;
// 	int	int_len;

// 	len = 0;
// 	res = 1;
// 	int_len = INT_LEN;
// 	if (str)
// 		len = ft_strlen(str);
// 	if (str[0] == '-')
// 		int_len++;
// 	if (len > int_len)
// 		return (--res);
// 	else if (len == int_len)
// 		return (check_str(str, int_len));
// 	printf("str : %s len : %d, int_len : %d, res : %d\n", str, len, int_len, res);
// 	return (res);
// }
// long long num;



// while (str[i])
// {
// 	if (!)
// 		error
// 	if (str[i]> '0' && str[i] <= '9';
// 		num += num * 10 + 
// 	if (num > 214 | )
// }

// int	check_str(char *str, int int_len)
// {
// 	int		i;
// 	char	*int_str;

// 	i = 0;
// 	int_str = MAX_INT;
// 	if (str[0] == '-')
// 		int_str = MIN_INT;
// 	while (i < int_len && str[i])
// 	{
// 		printf("str[%d] : %c int_str[%d] : %c\n", i, str[i], i, int_str[i]);
// 		if (str[i] > int_str[i])
// 			return (0);
// 		i++;
// 	}
// 	printf("str : %s int_str : %s", str, int_str);
// 	return (1);
// }