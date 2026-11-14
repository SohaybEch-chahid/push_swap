/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:10 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:02:06 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_data *stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || stack->size_stack < 2)
		return ;
	first = stack->stack;
	stack->stack = first->next;
	first->next = NULL;
	last = stack->stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ft_ra(t_data *stack_A)
{
	ft_rotate(stack_A);
}

void	ft_rb(t_data *stack_B)
{
	ft_rotate(stack_B);
}

void	ft_rr(t_data *stack_A, t_data *stack_B)
{
	ft_rotate(stack_A);
	ft_rotate(stack_B);
}
