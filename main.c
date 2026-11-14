/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:57:22 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 16:36:34 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void	add_top(t_data *stack, int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(1);
	node->value = value;
	node->next = stack->stack;
	stack->stack = node;
	stack->size_stack++;
}

static void	show_stack(char *name, t_data *stack)
{
	t_stack	*current;

	printf("%s: ", name);
	current = stack->stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
	fflush(stdout);
}

static void	clear_stack(t_data *stack)
{
	t_stack	*tmp;

	while (stack->stack)
	{
		tmp = stack->stack->next;
		free(stack->stack);
		stack->stack = tmp;
	}
	stack->size_stack = 0;
}

int	main(void)
{
	t_data	a;
	t_data	b;
	t_data	empty;

	a.stack = NULL;
	a.size_stack = 0;
	b.stack = NULL;
	b.size_stack = 0;
	empty.stack = NULL;
	empty.size_stack = 0;

	add_top(&a, 1);
	add_top(&a, 2);
	add_top(&a, 3);
	add_top(&a, 4);
	add_top(&b, 7);
	add_top(&b, 8);

	show_stack("Initial A", &a);
	show_stack("Initial B", &b);

	ft_sa(&a);
	show_stack("After sa", &a);

	ft_sb(&b);
	show_stack("After sb", &b);

	ft_ss(&a, &b);
	show_stack("After ss - A", &a);
	show_stack("After ss - B", &b);

	ft_rr(&a, &b);
	show_stack("After rr - A", &a);
	show_stack("After rr - B", &b);

	ft_rrr(&a, &b);
	show_stack("After rrr - A", &a);
	show_stack("After rrr - B", &b);

	ft_pb(&a, &b);
	show_stack("After pb - A", &a);
	show_stack("After pb - B", &b);

	ft_pa(&a, &b);
	show_stack("After pa - A", &a);
	show_stack("After pa - B", &b);

	ft_ra(&a);
	show_stack("After ra", &a);

	ft_rra(&a);
	show_stack("After rra", &a);

	ft_rb(&b);
	show_stack("After rb", &b);

	ft_rrb(&b);
	show_stack("After rrb", &b);

	/* Test operations on empty stacks */
	ft_sa(&empty);
	ft_sb(&empty);
	ft_ss(&empty, &empty);
	ft_pa(&a, &empty);
	ft_pb(&empty, &b);
	ft_ra(&empty);
	ft_rra(&empty);
	ft_rr(&empty, &empty);
	ft_rrr(&empty, &empty);

	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
