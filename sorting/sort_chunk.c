/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:39:26 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/18 11:07:59 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_get_racine(int nb)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= nb)
		i++;
	return (i);
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

static void	ft_push_chunk(t_data *a, t_data *b, int start, int end, int target)
{
	int	pushed;

	pushed = 0;
	while (pushed < target)
	{
		if (a->stack->index >= start && a->stack->index < end)
		{
			ft_pb(a, b);
			pushed++;
		}
		else
			ft_ra(a);
	}
}

static void	ft_distribute_chunks(t_data *a, t_data *b, int total)
{
	int	chunk_size;
	int	start;
	int	end;
	int	target;

	chunk_size = ft_get_racine(total);
	start = 0;
	while (start < total)
	{
		end = start + chunk_size;
		if (end > total)
			end = total;
		target = end - start;
		ft_push_chunk(a, b, start, end, target);
		start = end;
	}
}

static int	ft_get_max_pos(t_data *stack)
{
	t_stack	*current;
	int		max;
	int		pos;
	int		max_pos;

	current = stack->stack;
	max = current->index;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	ft_move_max_to_top(t_data *stack)
{
	int	pos;
	int	size;

	size = stack->size_stack;
	pos = ft_get_max_pos(stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_rb(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			ft_rrb(stack);
	}
}

static void	ft_rebuild_stack(t_data *a, t_data *b)
{
	while (b->stack)
	{
		ft_move_max_to_top(b);
		ft_pa(a, b);
	}
}

void	ft_sort_chunk(t_data *stack_a, t_data *stack_b)
{
	int	total;

	if (!stack_a || !stack_b || !stack_a->stack)
		return ;
	total = stack_a->size_stack;
	ft_index_stack(stack_a);
	ft_distribute_chunks(stack_a, stack_b, total);
	ft_rebuild_stack(stack_a, stack_b);
}
