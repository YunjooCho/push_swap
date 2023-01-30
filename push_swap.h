/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/01/30 21:37:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include "limits.h"
# include "ps_deque.h"

void	print_arg(int ac, char **av);
void	print_exit(int flag);
int		is_correct_arg(int ac);
void	parsing_argv(char **av, t_stack *stack);
void	split_atoi(char *str, t_stack *stack, int *order);
int		ps_atoi(char *str);
int		is_plus_minus(char *str, int i);
int		is_all_zero(char *str, int i);
int		ps_atoi(char *str);
void	free_matrix(char **arr);

void	ps_command(char *str, t_stack *stack_a, t_stack *stack_b);
void	cmd_sasb(t_stack *stack);
void	cmd_papb(t_stack *stack_from, t_stack *stack_to);
void	cmd_rarb(t_stack *stack);
void	cmd_rrarrb(t_stack *stack);
void	sort_under_five(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr, int *cmd_cnt);
void	init_checkarr(t_stack *stack_a, int *check, int len);
void	sort_two_elem(t_stack *stack, t_elem **order_arr, int *cmd_cnt);
void	sort_tree_elem(t_stack *stack, t_elem **order_arr, int *cmd_cnt);
void	sort_four_elem(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr, int *cmd_cnt);
void	sort_deque(t_stack *stack_a, t_stack *stack_b, int *cmd_cnt);
void	setting_order(t_elem **order_arr, t_stack *stack_a, int ac);

void	sort_arr(t_elem **order_arr, int ac);
void	print_arr(t_elem **order_arr, int ac);
void	init_lengarr(int *arr, int ac);

#endif