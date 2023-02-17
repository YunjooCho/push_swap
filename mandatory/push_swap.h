/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:30:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/02/17 19:29:34 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"
# include "ps_deque.h"
# include <unistd.h>

#include <stdio.h> //TODO - 지우기

typedef struct s_info
{
	int	total_cnt;
	int	a_cnt;
	int	b_cnt;
	int	ab_cnt;
	int	a_flag;
	int	b_flag;
	int	ab_flag;
}	t_info;

void	print_exit(int flag);
int		is_correct_arg(int ac);
int		check_sort(t_stack *stack_a);
void	free_matrix(char **arr);
void	free_orderarr(t_elem **order_arr);
char	*ps_strjoin(char *s1, char *s2);
void	parsing_argv(char **av, t_stack *stack);
void	split_atoi(char *str, t_stack *stack, int *order);
int		is_plus_minus(char *str, int i);
int		is_all_zero(char *str, int i);
int		ps_atoi(char *str);
t_elem	**indexing_order(t_elem **order_arr, t_stack *stack_a, int ac);
t_elem	**sort_order(t_elem **order_arr, t_stack *stack_a);
void	swap_orderarr(t_elem **order_arr, int i, int j);
int		check_arr(t_elem **order_arr, int ac);
void	init_checkarr(t_stack *stack_a, int *check, int len);
void	init_pivot(int *pia, int *pib, int len);
void	init_info(t_info *info);
void	init_flag(t_info *move);
void	init_abmove(t_info *move);
void	init_idxmax(t_stack *stack);
void	sort_under_five(t_stack *stack_a, t_stack *stack_b);
void	sort_above_five(t_stack *stack_a, t_stack *stack_b);
void	move_stackb(t_stack *stack_a, t_stack *stack_b, int pia, int pib);
void	move_stacka(t_stack *stack_a, t_stack *stack_b);
void	sort_two_elem(t_stack *stack_a, t_stack *stack_b);
void	reverse_two_elem(t_stack *stack_a, t_stack *stack_b);
void	sort_three_elem(t_stack *stack_a, t_stack *stack_b);
void	sort_four_elem(t_stack *stack_a, t_stack *stack_b);
void	sort_five_elem(t_stack *stack_a, t_stack *stack_b);
void	moving_elem(t_stack *stack_a, t_stack *stack_b, t_info *move);
char	*moving_rotate(t_info *move);
void	sorting_asc(t_stack *stack_a, t_stack *stack_b, t_info *move);
t_info	check_movecnt(t_stack *stack_a, t_stack *stack_b);
int		calcuate_movecnt(t_stack *stack, int target_idx);
int		calculate_movecnta(t_stack *stack_a, t_elem *tmp);
void	calculate_totalcnt(t_elem *tmp, t_info *cur);
void	ps_command(char *str, t_stack *stack_a, t_stack *stack_b);
void	command_swap(char *str, t_stack *stack_a, t_stack *stack_b, \
int str_len);
void	command_push(char *str, t_stack *stack_a, t_stack *stack_b, \
int str_len);
void	command_rotate(char *str, t_stack *stack_a, t_stack *stack_b, \
int str_len);
void	cmd_sasb(t_stack *stack);
void	cmd_papb(t_stack *stack_from, t_stack *stack_to);
void	cmd_rarb(t_stack *stack);
void	cmd_rrarrb(t_stack *stack);

#endif