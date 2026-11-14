/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:24 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:08:38 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_duplicates(t_data *data)
{
	t_stack	*current;
	t_stack	*runner;

	if (!data)
		return (0);
	current = data->stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

