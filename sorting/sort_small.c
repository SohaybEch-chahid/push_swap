/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:44 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/19 14:16:06 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_is_sorted(t_data *stack)
{
    t_stack *node;

    if (!stack || !stack->stack || !stack->stack->next)
        return (1);
    node = stack->stack;
    while (node->next)
    {
        if (node->value > node->next->value)
            return (0);
        node = node->next;
    }
    return (1);
}

static int ft_min_position(t_data *stack)
{
    t_stack *node = stack->stack;
    int min = node->value;
    int pos = 0;
    int min_pos = 0;

    while (node)
    {
        if (node->value < min)
        {
            min = node->value;
            min_pos = pos;
        }
        pos++;
        node = node->next;
    }
    return (min_pos);
}

static void ft_min_to_top(t_data *stack)
{
    int pos = ft_min_position(stack);

    if (pos <= stack->size_stack / 2)
    {
        while (pos-- > 0)
            ft_ra(stack);
    }
    else
    {
        pos = stack->size_stack - pos;
        while (pos-- > 0)
            ft_rra(stack);
    }
}

void ft_sort_selection(t_data *a, t_data *b)
{
    if (!a || !b || ft_is_sorted(a))
        return;
    while (a->size_stack > 1)
    {
        ft_min_to_top(a);
        ft_pb(a, b);
    }
    while (b->stack)
        ft_pa(a, b);
}
