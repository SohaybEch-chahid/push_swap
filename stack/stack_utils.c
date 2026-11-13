/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:51:09 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 13:59:13 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/ft_printf.h"
#include "../push_swap.h"

int	is_empty(t_data *data)
{
	return (!data || data->stack == NULL);
}

void	ft_push(t_data *data, int value)
{
	t_stack	*node;

	if (!data)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	node->next = data->stack;
	data->stack = node;
	data->size_stack++;
}

int	ft_pop(t_data *data, int *value)
{
	t_stack	*tmp;

	if (!data || !value || is_empty(data))
		return (0);
	tmp = data->stack;
	*value = tmp->value;
	data->stack = tmp->next;
	free(tmp);
	data->size_stack--;
	return (1);
}

void	ft_display_stack(t_data *data)
{
	t_stack	*current;

	if (!data)
		return ;
	current = data->stack;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}
