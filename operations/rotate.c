/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:10 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/12 03:35:19 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack *stack_A)
{
	t_stack	*tmp_stack;
	int		popped;
	int		tmp;

	ft_pop(&stack_A, &popped);
	tmp_stack = NULL;
	while (stack_A)
	{
		ft_pop(&stack_A, &tmp);
		ft_push(&tmp_stack, tmp);
	}
	ft_push(&stack_A, popped);
	while (tmp_stack)
	{
		ft_pop(&tmp_stack, &tmp);
		ft_push(&stack_A, tmp);
	}
}

void	ft_rb(t_stack *stack_B)
{
	t_stack	*tmp_stack;
	int		popped;
	int		tmp;

	ft_pop(&stack_B, &popped);
	tmp_stack = NULL;
	while (stack_B)
	{
		ft_pop(&stack_B, &tmp);
		ft_push(&tmp_stack, tmp);
	}
	ft_push(&stack_B, popped);
	while (tmp_stack)
	{
		ft_pop(&tmp_stack, &tmp);
		ft_push(&stack_B, tmp);
	}
}
void	ft_rr(t_stack *stack_A, t_stack *stack_B)
{
    ft_ra(stack_A);
    ft_rb(stack_B);
}

