/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:02 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 10:32:41 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_data **top)
{
    t_data **current;
    t_data *tmp;

    if (!top && !*top)
        return;
    current = top;
    while (*current) {
        tmp->stack = (*current)->stack;
        (*current)->stack = (*current)->stack->next;
        free(tmp);
    }
}
