/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:39 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/17 15:30:56 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include "../push_swap.h"

int	ft_get_max_number(t_stack *stack)
{
	t_stack	*current;
	int		max;

	current = stack;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}
int		ft_get_len_nb(int nb);

void	ft_sort_radix(t_data *stack_a, t_data *stack_b)
{
	int	max;
	int	*arr;
	int	len;
	int	*res;
	int	pos;
	int	i;

	// firt get the max of the stack_a
	// then create array of 10 cases
	// get the last index of the nember
	// go to thin index in the array and add one
	// then accumilaite the previous case with the current case
	// then push into stack_b each index
	max = ft_get_max_number(stack_a->stack);
	pos = 1;
	while (max / pos > 0) // log n or b numers of index of the max numers
	{
		arr = ft_calloc(10, sizeof(int));
		if (!arr)
			return ;
		while (stack_a->stack)
		{
			arr[(stack_a->stack->value / pos) % 10]++;
			stack_a->stack = stack_a->stack->next;
		}
		i = 1;
		while (i < 10)
		{
			arr[i] = arr[i - 1] + arr[i];
			i++;
		}
        i = 0;
        while (i < 10) {
            ft_pb()
            i++;
        }
		pos *= 10;
	}
	res = ft_calloc(stack_a->size_stack, sizeof(int));
	if (!res)
		return ;
}
