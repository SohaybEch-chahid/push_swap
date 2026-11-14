/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:02 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:21:17 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_data *top)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!top)
		return ;
	current = top->stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	top->stack = NULL;
	top->size_stack = 0;
}
