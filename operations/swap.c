/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:14 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 11:44:37 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_data *stack_A)
{
	int	popped1;
	int	popped2;

	if (stack_A->size_stack < 2)
		return ;
	ft_pop(stack_A, &popped1);
	ft_pop(stack_A, &popped2);
	ft_push(stack_A, popped1);
	ft_push(stack_A, popped2);
}

void	ft_sb(t_data *stack_B)
{
	int	popped1;
	int	popped2;

	if (stack_B->size_stack < 2)
		return ;
	ft_pop(stack_B, &popped1);
	ft_pop(stack_B, &popped2);
	ft_push(stack_B, popped1);
	ft_push(stack_B, popped2);
}

void	ft_ss(t_data *stack_A, t_data *stack_B)
{
	if (stack_A->size_stack < 2 || stack_B->size_stack < 2)
		return ;
	ft_sa(stack_A);
	ft_sa(stack_B);
}
