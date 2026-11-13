/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:49:48 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/13 10:09:59 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
	}
	return ((int)(res * sign));
}

t_data	*ft_create_stack(int argc, char **argv)
{
	int		i;
	int		nb;
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	stack->stack->next = NULL;
	stack->size_stack = -1;

	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		ft_push(&stack, nb);
		i++;
	}
	return (stack);
}
