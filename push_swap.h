/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 14:52:58 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include "limits.h"
# include "ps_deque.h"

void	print_arg(int ac, char **av);
void	print_error_exit(void);
int		is_correct_arg(int ac);
int		ps_atoi(char *str);
void	parsing_argv(char **av, t_stack *a);
void	split_arg(char *str, t_stack *a);

#endif