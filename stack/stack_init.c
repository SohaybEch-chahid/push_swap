/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:49:48 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/14 15:14:08 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_data	*ft_create_stack(int ac, char **av)
{
	int		i;
	t_data	*stack;
	t_stack	**tail;

	stack = malloc(sizeof(t_data));
	if (!stack)
		return (NULL);
	stack->stack = NULL;
	stack->size_stack = 0;
	tail = &stack->stack;
	i = 1;
	while (i < ac)
	{
		if (!ft_parse_numbers(stack, av[i], &tail))
		{
			ft_free_stack(stack);
			free(stack);
			return (NULL);
		}
		i++;
	}
	if (!ft_check_duplicates(stack))
	{
		ft_free_stack(stack);
		free(stack);
		return (NULL);
	}
	return (stack);
}
