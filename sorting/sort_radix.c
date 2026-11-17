/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:39 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/17 18:55:23 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			ft_get_max_index(t_stack *stack);
int			ft_get_passes_nb(int nb);

int			*ft_copy_stack_to_array(t_stack *stack);
void		ft_merge_sort(int *arr);
int			ft_binary_search(int *arr);

static void	ft_index_stack(t_data *stack)
{
	t_stack	*i;
	int		*arr;
	int		index;

	arr = ft_copy_stack_to_array(stack->stack); // n
	ft_merge_sort(arr);                         // n log n
	i = stack->stack;
	while (i)
	{
		index = ft_binary_search(arr); // log n
		i->index = index;
		i = i->next;
	}
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
	ft_index_stack(stack_a);
	max_bits = ft_get_passes_nb(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((stack_a->stack->index >> bit) & 1) == 0)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			i++;
		}
		while (stack_b->stack)
			ft_pa(stack_a, stack_b);
		bit++;
	}
}

/*
Instead of sorting the original numbers, we sort their indexes
form this [-5, 2, 0, -1, 3] to this [0, 3, 2, 1, 4]
Now Radix Sort works perfectly because every value is nonnegative!
*/
