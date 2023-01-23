/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/23 17:30:45 by yunjcho          ###   ########.fr       */
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
void	parsing_argv(char **av, t_stack *a);
void	split_arg(char *str, t_stack *a);
int		ps_atoi(char *str);
int		is_plus_minus(char *str, int i);
int		is_all_zero(char *str, int i);
int		ps_atoi(char *str);
void	free_matrix(char **arr);

void	ps_command(char *str, t_stack *stack_a, t_stack *stack_b);
void	cmd_sasb(t_stack *stack);
void	cmd_papb(t_stack *stack_from, t_stack *stack_to);

#endif