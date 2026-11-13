/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:09 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 10:14:21 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	is_empty(t_data *data)
{
	return (data->stack->next == NULL);
}

void	ft_push(t_data **top, int value)
{
	t_data	*node;

	node->stack = malloc(sizeof(t_data));
	if (!node)
		return ;
	node->stack->value = value;
	node->size_stack++;
	node->stack->next = (*top)->stack;
	*top = node;
}

int	ft_pop(t_data **top, int *value)
{
	t_data	*tmp;

	if (is_empty(*top))
	{
		return (0);
	}
	tmp = *top;
	*value = tmp->stack->value;
	(*top)->stack = (*top)->stack->next;
	(*top)->size_stack--;
	free(tmp);
	return (1);
}

void	ft_display_stack(t_data *top)
{
	t_data	*current;

	if (is_empty(top))
		return ;
	current = top;
	while (current)
	{
		ft_printf("%d\n", current->stack->value);
		current->stack = current->stack->next;
	}
}
