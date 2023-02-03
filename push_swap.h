/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/03 20:18:47 by yunjcho          ###   ########.fr       */
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
void	cmd_sasb(t_stack *stack, char *str);
void	cmd_papb(t_stack *stack_from, t_stack *stack_to, char *str);
void	cmd_rarb(t_stack *stack, char *str);
void	cmd_rrarrb(t_stack *stack, char *str);
void	sort_under_five(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr);
void	init_checkarr(t_stack *stack_a, int *check, int len);
void	sort_two_elem(t_stack *stack, t_elem **order_arr);
void	reverse_two_elem(t_stack *stack);
void	sort_three_elem(t_stack *stack_a, t_elem **order_arr);
void	sort_four_elem(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr);
void	sort_five_elem(t_stack *stack_a, t_stack *stack_b, t_elem **order_arr);
void	sort_deque(t_stack *stack_a, t_stack *stack_b);
t_elem	**setting_order(t_elem **order_arr, t_stack *stack_a, int ac);
int		check_arr(t_elem **order_arr, int ac);
int		check_sort(t_stack *stack_a);
t_elem	**sort_arr(t_elem **order_arr, int ac);
void	print_arr(t_elem **order_arr, int ac);
void	init_lengarr(int *arr, int ac);

void	free_orderarr(t_elem **order_arr, int ac); //leaks 필요없으면 지우기

#endif