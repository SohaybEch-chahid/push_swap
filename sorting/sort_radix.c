/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:39 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/19 14:46:35 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_passes_nb(int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb = nb >> 1;
	}
	return (len);
}

void	ft_sort_radix(t_data *stack_a, t_data *stack_b)
{
	int	max_bits;
	int	size;
	int	bit;
	int	i;

	size = stack_a->size_stack;
	if (size <= 1)
		return ;
	if (!ft_index_stack(stack_a))
		return ;
	max_bits = ft_get_passes_nb(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((stack_a->stack->index >> bit) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			i++;
		}
		while (stack_b->stack)
			ft_pa(stack_a, stack_b);
		bit++;
	}
}
