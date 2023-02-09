#include "push_swap.h"

void	ps_command(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	str_len;

	if (!str || !stack_a || !stack_b)
		return ;
	str_len = ft_strlen(str);
	if (!ft_strncmp(str, "sa", str_len))
		cmd_sasb(stack_a);
	else if (!ft_strncmp(str, "sb", str_len))
		cmd_sasb(stack_b);
	else if (!ft_strncmp(str, "ss", str_len))
	{
		cmd_sasb(stack_a);
		cmd_sasb(stack_b);
	}
	else if (!ft_strncmp(str, "pa", str_len))
		cmd_papb(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb", str_len))
		cmd_papb(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra", str_len))
		cmd_rarb(stack_a);
	else if (!ft_strncmp(str, "rb", str_len))
		cmd_rarb(stack_b);
	else if (!ft_strncmp(str, "rr", str_len))
	{
		cmd_rarb(stack_a);
		cmd_rarb(stack_b);
	}
	else if (!ft_strncmp(str, "rra", str_len))
		cmd_rrarrb(stack_a);
	else if (!ft_strncmp(str, "rrb", str_len))
		cmd_rrarrb(stack_b);
	else if (!ft_strncmp(str, "rrr", str_len))
	{
		cmd_rrarrb(stack_a);
		cmd_rrarrb(stack_b);
	}
	printf("%s\n", str);
}

// void	cmd_sasb(t_stack *stack, char *str)
void	cmd_sasb(t_stack *stack)
{
	t_elem	*tmp_top;
	t_elem	*tmp_sec;

	if (!stack->head || stack->cnt <= 1)
		return ;
	tmp_top = pop_front(stack);
	tmp_sec = pop_front(stack);
	append_front(stack, tmp_top->num, &tmp_top->order);
	append_front(stack, tmp_sec->num, &tmp_sec->order);
	free(tmp_top);
	free(tmp_sec);
	// printf("%s\n", str);
	init_idxmax(stack);
}

// void	cmd_papb(t_stack *stack_from, t_stack *stack_to, char *str)
void	cmd_papb(t_stack *stack_from, t_stack *stack_to)
{
	t_elem	*tmp;

	tmp = 0;
	if (stack_from->cnt == 0)
		return ;
	tmp = pop_front(stack_from);
	append_front(stack_to, tmp->num, &tmp->order);
	free(tmp);
	init_idxmax(stack_from);
	init_idxmax(stack_to);
	// printf("%s\n", str);
}

// void	cmd_rarb(t_stack *stack, char *str)
void	cmd_rarb(t_stack *stack)
{
	t_elem	*tmp;

	tmp = 0;
	if (!stack->head || stack->cnt <= 1)
		return ;
	tmp = pop_front(stack);
	append_back(stack, tmp->num, &tmp->order);
	free(tmp);
	// printf("%s\n", str);
	init_idxmax(stack);
}

// void	cmd_rrarrb(t_stack *stack, char *str)
void	cmd_rrarrb(t_stack *stack)
{
	t_elem	*tmp;

	tmp = 0;
	if (!stack->head || stack->cnt <= 1)
		return ;
	tmp = pop_back(stack);
	append_front(stack, tmp->num, &tmp->order);
	free(tmp);
	// printf("%s\n", str);
	init_idxmax(stack);
}

void	init_idxmax(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack->head;
	stack->max = -2147483648;
	while (tmp)
	{
		if (tmp->order > stack->max)
			stack->max = tmp->order;
		tmp->idx = i;
		i++;
		tmp = tmp->next;
	}
}