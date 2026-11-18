/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:39 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 11:04:47 by sech-cha         ###   ########.fr       */
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

int	*ft_copy_stack_to_array(t_data *stack)
{
	t_stack	*current;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * stack->size_stack);
	if (!arr)
		return (NULL);
	current = stack->stack;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

void	ft_merge(int *arr, int left, int mid, int right)
{
	int	i;
	int	j;
	int	k;
	int	n1;
	int	n2;
	int	*tl;
	int	*tr;

	n1 = mid - left + 1;
	n2 = right - mid;
	tl = malloc(sizeof(int) * n1);
	tr = malloc(sizeof(int) * n2);
	if (!tl || !tr)
	{
		free(tl);
		free(tr);
		return ;
	}
	i = 0;
	while (i < n1)
	{
		tl[i] = arr[left + i];
		i++;
	}
	j = 0;
	while (j < n2)
	{
		tr[j] = arr[mid + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (tl[i] > tr[j])
			arr[k++] = tr[j++];
		else
			arr[k++] = tl[i++];
	}
	while (i < n1)
		arr[k++] = tl[i++];
	while (j < n2)
		arr[k++] = tr[j++];
}

void	ft_merge_sort(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_merge_sort(arr, left, mid);
		ft_merge_sort(arr, mid + 1, right);
		ft_merge(arr, left, mid, right);
	}
}

int	ft_binary_search(int *arr, int len, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else if (arr[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

static int	ft_index_stack(t_data *stack)
{
	t_stack	*i;
	int		*arr;
	int		index;

	arr = ft_copy_stack_to_array(stack);
	if (!arr)
		return (0);
	ft_merge_sort(arr, 0, stack->size_stack - 1);
	i = stack->stack;
	while (i)
	{
		index = ft_binary_search(arr, stack->size_stack, i->value);
		if (index < 0)
		{
			free(arr);
			return (0);
		}
		i->index = index;
		i = i->next;
	}
	free(arr);
	return (1);
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
		// Because your maximum index is (size - 1)
	bit = 0;
	while (bit < max_bits) // log n
	{
		i = 0;
		while (i < size) // n
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
