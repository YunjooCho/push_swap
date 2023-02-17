/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:14:59 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/17 23:39:27 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_start_idx(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	set_len;

	i = -1;
	set_len = ft_strlen(set);
	while (s1[++i])
	{
		j = -1;
		while (set[++j])
		{
			if (s1[i] == set[j])
				break ;
		}
		if (j == set_len)
		{
			return (i);
		}
	}
	return (i);
}

int	get_end_idx(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;
	int	set_len;

	i = -1;
	set_len = ft_strlen(set);
	while (s1[++i])
	{
		j = -1;
		while (set[++j])
		{
			if (s1[i] == set[j])
				break ;
		}
		if (j == set_len)
		{
			k = i;
		}
	}
	return (k);
}

char	*ps_strtrim(char *command, char *newline)
{
	int		start;
	int		end;
	int		n;
	char	*arr;

	if (!command)
		return (0);
	if (!newline)
		return (command);
	start = get_start_idx(command, newline);
	end = get_end_idx(command, newline);
	n = 0;
	arr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (arr == 0)
		return (0);
	while (start < end + 1)
	{
		arr[n] = command[start];
		n++;
		start++;
	}
	free(command);
	arr[n] = '\0';
	return (arr);
}

void	print_result(t_stack *stack_a, t_stack *stack_b)
{
	if (!check_sort(stack_a))
		ft_putendl_fd("KO", 1);
	else if (check_sort(stack_a) && !stack_b->cnt)
		ft_putendl_fd("OK", 1);
}
