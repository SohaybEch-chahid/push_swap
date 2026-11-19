#include "../push_swap.h"

void ft_pa(t_data *a, t_data *b)
{
    t_stack *node;

    if (!a || !b || !b->stack)
        return;
    node = b->stack;
    b->stack = node->next;
    b->size_stack--;
    node->next = a->stack;
    a->stack = node;
    a->size_stack++;
    (void)write(1, "pa\n", 3);
}

void ft_pb(t_data *a, t_data *b)
{
    t_stack *node;

    if (!a || !b || !a->stack)
        return;
    node = a->stack;
    a->stack = node->next;
    a->size_stack--;
    node->next = b->stack;
    b->stack = node;
    b->size_stack++;
    (void)write(1, "pb\n", 3);
}
