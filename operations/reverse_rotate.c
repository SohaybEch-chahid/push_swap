/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:05 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:04:38 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_reverse_rotate(t_data *stack)
{
	t_stack	*current;
	t_stack	*last;

	if (!stack || stack->size_stack < 2)
		return ;
	current = stack->stack;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = stack->stack;
	stack->stack = last;
}

void	ft_rra(t_data *stack_A)
{
	ft_reverse_rotate(stack_A);
}

void	ft_rrb(t_data *stack_B)
{
	ft_reverse_rotate(stack_B);
}

void	ft_rrr(t_data *stack_A, t_data *stack_B)
{
	ft_reverse_rotate(stack_A);
	ft_reverse_rotate(stack_B);
}
