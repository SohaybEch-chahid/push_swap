/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:00 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 14:47:31 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//No malloc().
//No free().
//No possibility of losing an element because allocation failed.
//Constant time: \(O(1)\).

#include "../push_swap.h"

void	ft_pa(t_data *stack_A, t_data *stack_B)
{
	t_stack	*node;

	if (!stack_A || !stack_B || !stack_B->stack)
		return ;
	node = stack_B->stack;
	stack_B->stack = node->next;
	stack_B->size_stack--;
	node->next = stack_A->stack;
	stack_A->stack = node;
	stack_A->size_stack++;
}

void	ft_pb(t_data *stack_A, t_data *stack_B)
{
	t_stack	*node;

	if (!stack_A || !stack_B || !stack_A->stack)
		return ;
	node = stack_A->stack;
	stack_A->stack = node->next;
	stack_A->size_stack--;
	node->next = stack_B->stack;
	stack_B->stack = node;
	stack_B->size_stack++;
}
