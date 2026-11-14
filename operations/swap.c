/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:14 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 14:49:14 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_data *stack)
{
	int	tmp;

	if (!stack || stack->size_stack < 2)
		return ;
	tmp = stack->stack->value;
	stack->stack->value = stack->stack->next->value;
	stack->stack->next->value = tmp;
}

void	ft_sa(t_data *stack_A)
{
	ft_swap(stack_A);
}

void	ft_sb(t_data *stack_B)
{
	ft_swap(stack_B);
}

void	ft_ss(t_data *stack_A, t_data *stack_B)
{
	ft_swap(stack_A);
	ft_swap(stack_B);
}
