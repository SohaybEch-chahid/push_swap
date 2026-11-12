/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:09 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/12 03:24:26 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	is_empty(t_stack *top)
{
	return (top == NULL);
}

void	ft_push(t_stack **top, int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	node->next = *top;
	*top = node;
}

int	ft_pop(t_stack **top, int *value)
{
	t_stack	*tmp;

	if (is_empty(*top))
	{
		return (0);
	}
	tmp = *top;
	*value = tmp->value;
	*top = (*top)->next;
	free(tmp);
	return (1);
}

void	ft_display_stack(t_stack *top)
{
	t_stack	*current;

	if (is_empty(top))
		return ;
	current = top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}
