/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:14 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/12 03:18:22 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *stack_A)
{
	int	popped1;
	int	popped2;

	ft_pop(&stack_A, &popped1);
	ft_pop(&stack_A, &popped2);
	ft_push(&stack_A, popped1);
	ft_push(&stack_A, popped2);
}

void	ft_sb(t_stack *stack_B)
{
	int	popped1;
	int	popped2;

	ft_pop(&stack_B, &popped1);
	ft_pop(&stack_B, &popped2);
	ft_push(&stack_B, popped1);
	ft_push(&stack_B, popped2);
}
void	ft_ss(t_stack *stack_A, t_stack *stack_B)
{
	ft_sa(stack_A);
	ft_sa(stack_B);
}
