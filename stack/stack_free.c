/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:02 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/12 02:02:28 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **top)
{
    t_stack **current;
    t_stack *tmp;

    if (!top && !*top)
        return;
    current = top;
    while (*current) {
        tmp = *current;
        *current = (*current)->next;
        free(tmp);
    }
}
