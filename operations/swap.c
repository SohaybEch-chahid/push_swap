#include "../push_swap.h"

static int ft_swap(t_data *stack)
{
    int tmp;

    if (!stack || stack->size_stack < 2)
        return (0);
    tmp = stack->stack->value;
    stack->stack->value = stack->stack->next->value;
    stack->stack->next->value = tmp;
    tmp = stack->stack->index;
    stack->stack->index = stack->stack->next->index;
    stack->stack->next->index = tmp;
    return (1);
}

void ft_sa(t_data *a)
{
    if (ft_swap(a))
        (void)write(1, "sa\n", 3);
}

void ft_sb(t_data *b)
{
    if (ft_swap(b))
        (void)write(1, "sb\n", 3);
}

void ft_ss(t_data *a, t_data *b)
{
    int changed;

    changed = ft_swap(a);
    if (ft_swap(b))
        changed = 1;
    if (changed)
        (void)write(1, "ss\n", 3);
}
