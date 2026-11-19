#include "../push_swap.h"

static int ft_rotate(t_data *stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || stack->size_stack < 2)
        return (0);
    first = stack->stack;
    stack->stack = first->next;
    first->next = NULL;
    last = stack->stack;
    while (last->next)
        last = last->next;
    last->next = first;
    return (1);
}

void ft_ra(t_data *a)
{
    if (ft_rotate(a))
        (void)write(1, "ra\n", 3);
}

void ft_rb(t_data *b)
{
    if (ft_rotate(b))
        (void)write(1, "rb\n", 3);
}

void ft_rr(t_data *a, t_data *b)
{
    int changed;

    changed = ft_rotate(a);
    if (ft_rotate(b))
        changed = 1;
    if (changed)
        (void)write(1, "rr\n", 3);
}
