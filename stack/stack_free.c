/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:02 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 11:36:11 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_data *top)
{
    t_data *current;
    t_stack *tmp;

    if (!top)
        return;
    tmp = NULL;
    current = top;
    while (current->stack) {
        tmp= current->stack;
        current->stack = current->stack->next;
        free(tmp);
    }
    top->size_stack = 0;
}
