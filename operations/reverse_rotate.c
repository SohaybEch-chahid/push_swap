#include "../push_swap.h"

static int ft_reverse_rotate(t_data *stack)
{
    t_stack *current;
    t_stack *last;

    if (!stack || stack->size_stack < 2)
        return (0);
    current = stack->stack;
    while (current->next->next)
        current = current->next;
    last = current->next;
    current->next = NULL;
    last->next = stack->stack;
    stack->stack = last;
    return (1);
}

void ft_rra(t_data *a)
{
    if (ft_reverse_rotate(a))
        (void)write(1, "rra\n", 4);
}

void ft_rrb(t_data *b)
{
    if (ft_reverse_rotate(b))
        (void)write(1, "rrb\n", 4);
}

void ft_rrr(t_data *a, t_data *b)
{
    int changed;

    changed = ft_reverse_rotate(a);
    if (ft_reverse_rotate(b))
        changed = 1;
    if (changed)
        (void)write(1, "rrr\n", 4);
}
