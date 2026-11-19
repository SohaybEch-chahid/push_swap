/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:39:26 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/19 14:15:01 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_get_sqrt(int number)
{
    int root = 0;

    while (root + 1 <= number / (root + 1))
        root++;
    return (root);
}

static void ft_push_chunk(t_data *a, t_data *b, int start, int end, int target)
{
    int pushed = 0;

    while (pushed < target)
    {
        if (a->stack->index >= start && a->stack->index < end)
        {
            ft_pb(a, b);
            pushed++;
        }
        else
            ft_ra(a);
    }
}

static void ft_distribute_chunks(t_data *a, t_data *b, int total)
{
    int chunk_size = ft_get_sqrt(total);
    int start = 0;
    int end;

    if (chunk_size < 1)
        chunk_size = 1;
    while (start < total)
    {
        end = start + chunk_size;
        if (end > total)
            end = total;
        ft_push_chunk(a, b, start, end, end - start);
        start = end;
    }
}

static int ft_get_max_position(t_data *stack)
{
    t_stack *node = stack->stack;
    int max_index = node->index;
    int pos = 0;
    int max_pos = 0;

    while (node)
    {
        if (node->index > max_index)
        {
            max_index = node->index;
            max_pos = pos;
        }
        pos++;
        node = node->next;
    }
    return (max_pos);
}

static void ft_max_to_top(t_data *stack)
{
    int pos = ft_get_max_position(stack);
    int size = stack->size_stack;

    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ft_rb(stack);
    }
    else
    {
        pos = size - pos;
        while (pos-- > 0)
            ft_rrb(stack);
    }
}

static void ft_rebuild_stack(t_data *a, t_data *b)
{
    while (b->stack)
    {
        ft_max_to_top(b);
        ft_pa(a, b);
    }
}

void ft_sort_chunk(t_data *a, t_data *b)
{
    int total;

    if (!a || !b || !a->stack)
        return;
    total = a->size_stack;
    if (!ft_index_stack(a))
        return;
    ft_distribute_chunks(a, b, total);
    ft_rebuild_stack(a, b);
}
