/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:00 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/12 03:11:20 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack *stack_A, t_stack *stack_B)
{
	int	popped;

	ft_pop(&stack_A, &popped);
	ft_push(&stack_B, popped);
}
void	ft_pb(t_stack *stack_A, t_stack *stack_B)
{
	int	popped;

	ft_pop(&stack_B, &popped);
	ft_push(&stack_A, popped);
}
void	ft_pp(t_stack *stack_A, t_stack *stack_B)
{
	ft_pa(stack_A, stack_B);
	ft_pa(stack_B, stack_A);
}
