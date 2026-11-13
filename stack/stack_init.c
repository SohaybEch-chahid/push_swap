/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:49:48 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 15:23:26 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../../Libft/libft.h"

t_data	*ft_create_stack(int argc, char **argv)
{
	int		i;
	int		nb;
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	stack->stack = NULL;
	stack->size_stack = 0;

	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		ft_push(stack, nb);
		i++;
	}
	return (stack);
}
