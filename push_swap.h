/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/20 22:09:48 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include "limits.h"
# include "push_swap_deque.h"


void	print_argv(char **av);

void	print_error_exit(void);
int		ps_atoi(char *str);
int		is_correct_arg(int ac, char **av, t_stack *a);
// int		ft_isint(char *str);
// int		check_str(char *str, int int_len);
#endif