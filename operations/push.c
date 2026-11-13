/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:00 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 11:37:19 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_data *stack_A, t_data *stack_B)
{
	int	popped;

	if (stack_A->size_stack <= 0)
		return ;
	ft_pop(stack_A, &popped);
	ft_push(stack_B, popped);
}

void	ft_pb(t_data *stack_A, t_data *stack_B)
{
	int	popped;

	if (stack_B->size_stack <= 0)
		return ;
	ft_pop(stack_B, &popped);
	ft_push(stack_A, popped);
}

void	ft_pp(t_data *stack_A, t_data *stack_B)
{
	if (stack_A->size_stack <= 0 || stack_B->size_stack <= 0)
		return ;
	ft_pa(stack_A, stack_B);
	ft_pa(stack_B, stack_A);
}
