/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:10 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 11:52:08 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_data *stack_A)
{
	t_data	*tmp_stack;
	int		popped;
	int		tmp;

	if (stack_A->size_stack <= 0)
		return ;
	ft_pop(stack_A, &popped);
	tmp_stack = NULL;
	while (stack_A->stack)
	{
		ft_pop(stack_A, &tmp);
		ft_push(tmp_stack, tmp);
	}
	ft_push(stack_A, popped);
	while (tmp_stack->stack)
	{
		ft_pop(tmp_stack, &tmp);
		ft_push(stack_A, tmp);
	}
}

void	ft_rb(t_data *stack_B)
{
	t_data	*tmp_stack;
	int		popped;
	int		tmp;

	if (stack_B->size_stack <= 0)
		return ;
	ft_pop(stack_B, &popped);
	tmp_stack = NULL;
	while (stack_B->stack)
	{
		ft_pop(stack_B, &tmp);
		ft_push(tmp_stack, tmp);
	}
	ft_push(stack_B, popped);
	while (tmp_stack->stack)
	{
		ft_pop(tmp_stack, &tmp);
		ft_push(stack_B, tmp);
	}
}

void	ft_rr(t_data *stack_A, t_data *stack_B)
{
	if (stack_A->size_stack <= 0 || stack_B->size_stack <= 0)
		return ;
	ft_ra(stack_A);
	ft_rb(stack_B);
}
